//
//  RouteMatchingExampleFactory.cpp
//  ExampleApp
//
//  Created by Scott on 21/05/2014.
//  Copyright (c) 2014 eeGeo. All rights reserved.
//

#include "RouteMatchingExampleFactory.h"
#include "RouteMatchingExample.h"

using namespace Examples;

RouteMatchingExampleFactory::RouteMatchingExampleFactory(Eegeo::EegeoWorld& world,
                                                         const IRouteMatchingExampleViewFactory& routeMatchingViewFactory)
: m_world(world)
, m_routeMatchingViewFactory(routeMatchingViewFactory)
{
    
}

IExample* RouteMatchingExampleFactory::CreateExample() const
{
    return new Examples::RouteMatchingExample(m_world.GetRouteService(),
                                              m_world,
                                              m_routeMatchingViewFactory);
}

std::string RouteMatchingExampleFactory::ExampleName() const
{
	return Examples::RouteMatchingExample::GetName();
}