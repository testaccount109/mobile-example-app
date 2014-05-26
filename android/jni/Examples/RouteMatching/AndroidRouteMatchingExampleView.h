//
//  AndroidRouteMatchingExampleView.h
//  ExampleApp
//
//  Created by Scott on 19/05/2014.
//  Copyright (c) 2014 eeGeo. All rights reserved.
//

#ifndef __ExampleApp__AndroidRouteMatchingExampleView__
#define __ExampleApp__AndroidRouteMatchingExampleView__

#include "Types.h"
#include "IRouteMatchingExampleView.h"
#include "AndroidNativeState.h"
#include <vector>

namespace Examples
{
	class AndroidRouteMatchingProxy;

    class AndroidRouteMatchingExampleView : public IRouteMatchingExampleView, private Eegeo::NonCopyable
    {
        std::vector<IUIActionHandler*> m_matchingToggledHandlers;
    	AndroidNativeState& m_nativeState;
    	AndroidRouteMatchingProxy* m_pProxy;
    	jclass m_routeMatchingExampleHudClass;
    	jobject m_routeMatchingExampleHud;
        
    public:
        AndroidRouteMatchingExampleView(AndroidNativeState& androidNativeState, AndroidRouteMatchingProxy* pProxy);
        
        ~AndroidRouteMatchingExampleView();
        
        void AddMatchingToggledHandler(IUIActionHandler& handler);
        
        void RemoveMatchingToggledHandler(IUIActionHandler& handler);
        
        void ToggleMatching();
    };
}

#endif /* defined(__ExampleApp__AndroidRouteMatchingExampleView__) */