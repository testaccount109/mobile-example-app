// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include "ApplicationConfigurationService.h"
#include "IApplicationConfigurationParser.h"
#include "IApplicationConfigurationReader.h"

namespace ExampleApp
{
    namespace ApplicationConfig
    {
        namespace SdkModel
        {
            ApplicationConfigurationService::ApplicationConfigurationService(IApplicationConfigurationParser& parser,
                                                                             IApplicationConfigurationReader& reader,
                                                                             const std::string& productVersion,
                                                                             const std::string& buildNumber)
            : m_parser(parser)
            , m_reader(reader)
            , m_productVersion(productVersion)
            , m_buildNumber(buildNumber)
            {
                
            }
            
            ApplicationConfiguration ApplicationConfigurationService::LoadConfiguration(const std::string& path)
            {
                std::string serialized(m_reader.ReadApplicationConfiguration(path));
                const ApplicationConfiguration& parsedConfig = m_parser.ParseConfiguration(serialized);
                
                const std::string combinedVersionString = m_productVersion + "." + m_buildNumber;
                
                return ApplicationConfiguration(parsedConfig.Name(),
                                                parsedConfig.InterestLocation(),
                                                parsedConfig.DistanceToInterestMetres(),
                                                parsedConfig.OrientationDegrees(),
                                                parsedConfig.TryStartAtGpsLocation(),
                                                parsedConfig.GoogleAnalyticsReferrerToken(),
                                                m_productVersion,
                                                m_buildNumber,
                                                combinedVersionString,
                                                parsedConfig.CoverageTreeManifestURL(),
                                                parsedConfig.ThemeManifestURL());
            }
        }
    }
}
