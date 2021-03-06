// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include "TwitterFeedPinSelectionHandler.h"
#include "TourModel.h"
#include "TourStateModel.h"
#include "DeeplinkURLRequestedMessage.h"
#include "TweetModel.h"

namespace ExampleApp
{
    namespace Tours
    {
        namespace SdkModel
        {
            namespace TourInstances
            {
                namespace TwitterFeed
                {
                    TwitterFeedPinSelectionHandler::TwitterFeedPinSelectionHandler(const TourStateModel& tourStateModel,
                                                                                   ExampleAppMessaging::TMessageBus& messageBus)
                    : m_tourStateModel(tourStateModel)
                    , m_messageBus(messageBus)
                    {
                        
                    }
                    
                    TwitterFeedPinSelectionHandler::~TwitterFeedPinSelectionHandler()
                    {
                        
                    }
                    
                    void TwitterFeedPinSelectionHandler::SelectPin()
                    {
                        const Social::TwitterFeed::TweetModel& tweet = *m_tourStateModel.Tweet();
                        const std::string twitterDeeplinkUrl = "twitter://status?id="+tweet.GetTweetId();
                        const std::string twitterUrl = "https://www.twitter.com/" + tweet.GetUserScreenName() + "/status/"+ tweet.GetTweetId();
                        m_messageBus.Publish(URLRequest::DeeplinkURLRequestedMessage(twitterDeeplinkUrl, twitterUrl));
                    }
                }
            }
        }
    }
}
