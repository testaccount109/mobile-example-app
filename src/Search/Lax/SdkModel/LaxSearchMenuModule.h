// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "ILaxSearchMenuModule.h"
#include "Types.h"
#include "BidirectionalBus.h"

namespace ExampleApp
{
    namespace Search
    {
        namespace Lax
        {
            namespace SdkModel
            {
                class LaxSearchMenuModule : public ILaxSearchMenuModule, private Eegeo::NonCopyable
                {
                public:
                    LaxSearchMenuModule(Menu::View::IMenuViewModel& menuViewModel,
                                            ExampleAppMessaging::TMessageBus& messageBus);
                    
                    ~LaxSearchMenuModule();
                    
                    Menu::View::IMenuModel& GetDefibrillatorMenuModel() const;
                    Menu::View::IMenuModel& GetFoodMenuModel() const;
                    Menu::View::IMenuModel& GetShoppingMenuModel() const;
                    Menu::View::IMenuModel& GetElevatorMenuModel() const;
                    Menu::View::IMenuModel& GetStairsMenuModel() const;
                    Menu::View::IMenuModel& GetEscalatorMenuModel() const;
                    Menu::View::IMenuModel& GetRestroomMenuModel() const;
                    Menu::View::IMenuModel& GetTddpayphoneMenuModel() const;
                    Menu::View::IMenuModel& GetAtmMenuModel() const;
                    Menu::View::IMenuModel& GetPayphoneMenuModel() const;
                    Menu::View::IMenuModel& GetGateseMenuModel() const;
                    Menu::View::IMenuModel& GetOthersMenuModel() const;
                    
                private:
                    Menu::View::IMenuModel* m_pDefibrillatorMenuModel;
                    Menu::View::IMenuOptionsModel* m_pDefibrillatorMenuOptionsModel;

                    Menu::View::IMenuModel* m_pFoodMenuModel;
                    Menu::View::IMenuOptionsModel* m_pFoodMenuOptionsModel;

                    Menu::View::IMenuModel* m_pShoppingMenuModel;
                    Menu::View::IMenuOptionsModel* m_pShoppingMenuOptionsModel;

                    Menu::View::IMenuModel* m_pElevatorMenuModel;
                    Menu::View::IMenuOptionsModel* m_pElevatorMenuOptionsModel;

                    Menu::View::IMenuModel* m_pStairsMenuModel;
                    Menu::View::IMenuOptionsModel* m_pStairsMenuOptionsModel;

                    Menu::View::IMenuModel* m_pEscalatorMenuModel;
                    Menu::View::IMenuOptionsModel* m_pEscalatorMenuOptionsModel;
                    
                    
                    Menu::View::IMenuModel* m_pRestroomMenuModel;
                    Menu::View::IMenuOptionsModel* m_pRestroomMenuOptionsModel;

                    Menu::View::IMenuModel* m_pTddpayphoneMenuModel;
                    Menu::View::IMenuOptionsModel* m_pTddpayphoneMenuOptionsModel;

                    Menu::View::IMenuModel* m_pAtmMenuModel;
                    Menu::View::IMenuOptionsModel* m_pAtmMenuOptionsModel;

                    Menu::View::IMenuModel* m_pPayphoneMenuModel;
                    Menu::View::IMenuOptionsModel* m_pPayphoneMenuOptionsModel;

                    Menu::View::IMenuModel* m_pGatesMenuModel;
                    Menu::View::IMenuOptionsModel* m_pGatesMenuOptionsModel;

                    Menu::View::IMenuModel* m_pOthersMenuModel;
                    Menu::View::IMenuOptionsModel* m_pOthersMenuOptionsModel;
                    
                    
                };
            }
        }
    }
}