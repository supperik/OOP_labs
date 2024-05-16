#include "../../../catch2/catch_test_macros.hpp"
#include "HtmlEncode.h"

SCENARIO("Decode html string")
{
	WHEN("Html is empty")
	{
		std::string text = "";

		THEN("Decoded string is empty")
		{
			std::string encodedString = HtmlEncode(text);
			CHECK(HtmlEncode.empty());
		}
	}

	WHEN("Html don't has special substr")
	{
		std::string text = "It is text without special symbolsr";

		THEN("Encoded string equal text without special symbols")
		{
			std::string encodedString = HtmlEncode(text);
			CHECK(encodedString == html);
		}
	}

	WHEN("Html has specail substr")
	{
		std::string text = "Cat <says> \"Meow\". M&M's";
		THEN("Specail substr will be decoded to symbols")
		{
			std::string encodedString = HtmlEncode(text);
			CHECK(encodedString == "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
		}
	}

	WHEN("Specail substr not full")
	{
		std::string text = "Cat &ltsays&gt &quotMeow&quot. M&ampM&aposs";
		THEN("Specail substr will not decoded to symbols")
		{
			std::string encodedString = HtmlEncode(text);
			CHECK(encodedString == "Cat &ltsays&gt &quotMeow&quot. M&ampM&aposs");
		}
	}
}