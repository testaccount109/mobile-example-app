// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include <string>
#include "IMyPinsService.h"
#include "ISearchResultMyPinsService.h"
#include "SearchResultPoiMyPinService.h"
#include "ISearchResultIconCategoryMapper.h"

namespace ExampleApp
{
    namespace SearchResultPoi
    {
        namespace SdkModel
        {   
            SearchResultPoiMyPinService::SearchResultPoiMyPinService(MyPins::SdkModel::IMyPinsService& myPinsService,
                                                                     Search::SdkModel::MyPins::ISearchResultMyPinsService& searchResultMyPinsService,
                                                                     CategorySearch::ISearchResultIconCategoryMapper& searchResultIconCategoryMapper)
            : m_myPinsService(myPinsService)
            , m_searchResultMyPinsService(searchResultMyPinsService)
            , m_searchResultIconCategoryMapper(searchResultIconCategoryMapper)
            {
                
            }
            
            SearchResultPoiMyPinService::~SearchResultPoiMyPinService()
            {
                
            }
            
            void SearchResultPoiMyPinService::AddOrRemoveSearchResultFromMyPins(const Search::SdkModel::SearchResultModel& searchResult)
            {
                MyPins::SdkModel::MyPinModel myPinModel;
                
                if(m_searchResultMyPinsService.TryGetPinForSearchResult(searchResult, myPinModel))
                {
                    // The pin already exists, so remove it and return!
                    m_myPinsService.RemovePinWithId(myPinModel.Identifier());
                }
                else
                {
                    // The pin doesn't exist, so we must add it...
                    const int pinIconIndex = m_searchResultIconCategoryMapper.GetIconIndexFromSearchResult(searchResult);
                    m_myPinsService.SaveSearchResultPoiPin(searchResult, pinIconIndex);
                }
            }
        }
    }
}
