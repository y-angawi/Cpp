#include "TextBlock.h"

TextBlock::TextBlock(string s)
{
	flags = 0;	// 0x00000000
	text = s;
}
void TextBlock::print()
{
	cout << text << endl;
	cout << (isBold() ? "Bold" : "") << endl;
	cout << (isItalic() ? "Italic" : "") << endl;
	cout << (isUnderlined() ? "Underlined" : "") << endl;
	cout << (isHighlighted() ? "Highlighted" : "") << endl;
	cout << (isSubscript() ? "Subscript" : "") << endl;
	cout << (isStrikethrough() ? "Strikethrough" : "") << endl;
}
bool TextBlock::isBold()
{
	// 'AND' 'flags' with 'boldMask' to determine if bold bit is set or not
	return (flags & boldMask) > 0;
}
bool TextBlock::isItalic()
{
	return (flags & italicMask) > 0;
}
bool TextBlock::isUnderlined()
{
	return (flags & underlinedMask) > 0;
}
bool TextBlock::isHighlighted()
{
	return (flags & highlightMask) > 0;
}
bool TextBlock::isSubscript()
{
	return (flags & subscriptMask) > 0;
}
bool TextBlock::isStrikethrough()

	{
		return (flags & subscriptMask) > 0;
	}

void TextBlock::setBold(bool val)
{
	if (val)  // if true, set bold to true
	{
		// use 'OR' masking to set the 'bold' bit
		flags = flags | boldMask;
	}
	else  // val is false so, set bold bit to false (0)
	{
		//'AND' bold bit with the compliment of the boldMask
		flags = flags & ~boldMask;
	}
}
void TextBlock::setItalic(bool val)
{
	if (val)
	{
		flags = flags | italicMask;
	}
	else
	{
		flags = flags & ~italicMask;
	}
}
void TextBlock::setUnderlined(bool val)
{
	if (val)
	{
		flags = flags | underlinedMask;
	}
	else
	{
		flags = flags & ~underlinedMask;
	}
}
void TextBlock::setHighlighted(bool val)
{
	if (val)
	{
		flags = flags | highlightMask;
	}
	else
	{
		flags = flags & ~highlightMask;
	}
}
void TextBlock::setSubscript(bool val)
{
	if (val)
	{
		flags = flags | subscriptMask;
	}
	else
	{
		flags = flags & subscriptMask;
	}
}
void TextBlock::setStrikethrough(bool val)
{
	if (val)
	{
		flags = flags | strikethroughMask;
	}
	else
	{
		flags = flags & strikethroughMask;
	}
}

TextBlock::~TextBlock()
{
}
