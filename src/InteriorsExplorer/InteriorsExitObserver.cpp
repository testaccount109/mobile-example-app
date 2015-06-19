// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include "InteriorsExitObserver.h"
#include "InteriorsController.h"
#include "InteriorSelectionController.h"
#include "InteriorsCameraController.h"
#include "EcefTangentBasis.h"
#include "GpsGlobeCameraController.h"
#include "NativeUIFactories.h"
#include "IAlertBoxFactory.h"

namespace ExampleApp
{
    namespace InteriorsExplorer
    {
        InteriorsExitObserver::InteriorsExitObserver(Eegeo::Resources::Interiors::InteriorsController& interiorsController,
                                                     Eegeo::Resources::Interiors::InteriorSelectionController& interiorSelectionController,
                                                     Eegeo::Camera::GlobeCamera::GpsGlobeCameraController& globeCameraController,
                                                     Eegeo::UI::NativeUIFactories& nativeUiFactories)
        : m_interiorsController(interiorsController)
        , m_interiorSelectionController(interiorSelectionController)
        , m_globeCameraController(globeCameraController)
        , m_nativeUiFactories(nativeUiFactories)
        , m_pAlertBox(NULL)
        , m_onInteriorsControllerExitCallback(this, &InteriorsExitObserver::OnInteriorsControllerExit)
        , m_failedToStreamResourceCallback(this, &InteriorsExitObserver::OnFailedToStreamResource)
        {
            m_interiorsController.RegisterExitCallback(m_onInteriorsControllerExitCallback);
            m_interiorSelectionController.RegisterFailedToStreamResourceCallback(m_failedToStreamResourceCallback);
        }

        InteriorsExitObserver::~InteriorsExitObserver()
        {
            m_interiorsController.UnregisterExitCallback(m_onInteriorsControllerExitCallback);
            m_interiorSelectionController.UnregisterFailedToStreamResourceCallback(m_failedToStreamResourceCallback);
        }

        void InteriorsExitObserver::OnInteriorsControllerExit()
        {
            const float additionalDistanceOffset = 0.f;
            InitialiseTransitionToGlobeCamera(additionalDistanceOffset);
        }

        void InteriorsExitObserver::OnFailedToStreamResource()
        {
            Eegeo_ASSERT(m_pAlertBox == NULL);

            m_pAlertBox = m_nativeUiFactories.AlertBoxFactory().CreateSingleOptionAlertBox("Unable to download indoor map",
                    "Please check that you have a healthy network connection.",
                    *this);

            const float additionalDistanceOffset = 500.f;
            InitialiseTransitionToGlobeCamera(additionalDistanceOffset);
        }

        void InteriorsExitObserver::InitialiseTransitionToGlobeCamera(float additionalDistanceOffset)
        {
            const Eegeo::Resources::Interiors::Camera::InteriorsCameraState& defaultExitTransitionTarget = m_interiorsController.GetExitTransitionTarget();

            Eegeo::v3 camToInterest = (defaultExitTransitionTarget.GetInterestPointEcef() - defaultExitTransitionTarget.GetLocationEcef()).ToSingle();
            const Eegeo::v3& camDir = camToInterest.Norm();

            Eegeo::Space::EcefTangentBasis interestBasis(defaultExitTransitionTarget.GetInterestPointEcef(), camDir);

            float currentCameraDist = camToInterest.Length();

            m_globeCameraController.SetView(interestBasis, currentCameraDist + additionalDistanceOffset);

            const Eegeo::Resources::Interiors::Camera::InteriorsCameraState& exitTransitionTarget = Eegeo::Resources::Interiors::Camera::InteriorsCameraState::MakeFromRenderCamera(m_globeCameraController.GetRenderCamera());

            m_interiorsController.SetExitTransitionTarget(exitTransitionTarget);
        }

        void InteriorsExitObserver::HandleAlertBoxDismissed()
        {
            Eegeo_DELETE m_pAlertBox;
            m_pAlertBox = NULL;
        }
    }
}