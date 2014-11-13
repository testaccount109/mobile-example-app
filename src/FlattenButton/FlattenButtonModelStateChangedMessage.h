// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace ExampleApp
{
	namespace FlattenButton
	{
		class FlattenButtonModelStateChangedMessage
		{
			bool m_isFlattened;

		public:
			FlattenButtonModelStateChangedMessage(bool isFlattened)
				: m_isFlattened(isFlattened)
			{

			}

			bool IsFlattened() const
			{
				return m_isFlattened;
			}
		};
	}
}