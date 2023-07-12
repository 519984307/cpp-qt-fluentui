#include "FluentUiColorUtils.h"

FluentUiColorUtils::FluentUiColorUtils()
{
	Black	= QString("#000000");
	White	= QString("#ffffff");
	Grey10	= QString("#faf9f8");
	Grey20	= QString("#f3f2f1");
	Grey30	= QString("#edebe9");
	Grey40	= QString("#e1dfdd");
	Grey50	= QString("#d2d0ce");
	Grey60	= QString("#c8c6c4");
	Grey70	= QString("#beb9b8");
	Grey80	= QString("#b3b0ad");
	Grey90	= QString("#a19f9d");
	Grey100 = QString("#979592");
	Grey110 = QString("#8a8886");
	Grey120 = QString("#797775");
	Grey130 = QString("#605e5c");
	Grey140 = QString("#484644");
	Grey150 = QString("#3b3a39");
	Grey160 = QString("#323130");
	Grey170 = QString("#292827");
	Grey180 = QString("#252423");
	Grey190 = QString("#201f1e");
	Grey200 = QString("#1b1a19");
	Grey210 = QString("#161514");
	Grey220 = QString("#11100f");

	FluentUiColorSet tmpYellow;
	tmpYellow.darkest = QString("#f9a825");
	tmpYellow.darker = QString("#fbc02d");
	tmpYellow.dark = QString("#fdd435");
	tmpYellow.normal = QString("#ffeb3b");
	tmpYellow.light = QString("#ffee58");
	tmpYellow.lighter = QString("#fff176");
	tmpYellow.lightest = QString("#fff59b");
	Yellow = tmpYellow;

	FluentUiColorSet tmpOrange;
	tmpOrange.darkest = QString("#993d07");
	tmpOrange.darker = QString("#ac4408");
	tmpOrange.dark = QString("#d1580a");
	tmpOrange.normal = QString("#f7630c");
	tmpOrange.light = QString("#f87a30");
	tmpOrange.lighter = QString("#f99154");
	tmpOrange.lightest = QString("#fac06a");
	Orange = tmpOrange;

	FluentUiColorSet tmpRed;
	tmpRed.darkest = QString("#8f0a15");
	tmpRed.darker = QString("#a20b18");
	tmpRed.dark = QString("#b90d1c");
	tmpRed.normal = QString("#e81123");
	tmpRed.light = QString("#ec404f");
	tmpRed.lighter = QString("#ee5865");
	tmpRed.lightest = QString("#f06b76");
	Red = tmpRed;

	FluentUiColorSet tmpMagenta;
	tmpMagenta.darkest = QString("#6f004f");
	tmpMagenta.darker = QString("#a0076c");
	tmpMagenta.dark = QString("#b50d7d");
	tmpMagenta.normal = QString("#e3008c");
	tmpMagenta.light = QString("#ea4da8");
	tmpMagenta.lighter = QString("#ee6ec1");
	tmpMagenta.lightest = QString("#f18cd5");
	Magenta = tmpMagenta;

	FluentUiColorSet tmpPurple;
	tmpPurple.darkest = QString("#2c0f76");
	tmpPurple.darker = QString("#3d0f99");
	tmpPurple.dark = QString("#4e11ae");
	tmpPurple.normal = QString("#68217a");
	tmpPurple.light = QString("#7b4c9d");
	tmpPurple.lighter = QString("#8d6ebd");
	tmpPurple.lightest = QString("#9e8ed9");
	Purple = tmpPurple;

	FluentUiColorSet tmpBlue;
	tmpBlue.darkest = QString("#004A83");
	tmpBlue.darker = QString("#005494");
	tmpBlue.dark = QString("#0066B4");
	tmpBlue.normal = QString("#0078D4");
	tmpBlue.light = QString("#268CDC");
	tmpBlue.lighter = QString("#4CA0E0");
	tmpBlue.lightest = QString("#60ABE4");
	Blue = tmpBlue;

	FluentUiColorSet tmpTeal;
	tmpTeal.darkest = QString("#006E5B");
	tmpTeal.darker = QString("#007C67");
	tmpTeal.dark = QString("#00977D");
	tmpTeal.normal = QString("#00B294");
	tmpTeal.light = QString("#26BDA4");
	tmpTeal.lighter = QString("#4DC9B4");
	tmpTeal.lightest = QString("#60CFBC");
	Teal = tmpTeal;

	FluentUiColorSet tmpGreen;
	tmpGreen.darkest = QString("#094C09");
	tmpGreen.darker = QString("#0C5D0C");
	tmpGreen.dark = QString("#0E6F0E");
	tmpGreen.normal = QString("#107C10");
	tmpGreen.light = QString("#278939");
	tmpGreen.lighter = QString("#4C9C4C");
	tmpGreen.lightest = QString("#6AAD6A");
	Green = tmpGreen;

}
