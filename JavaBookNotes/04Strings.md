# Strings in Java
- Strings are objects in Java, and they are immutable.
- Strings are stored in the String Pool, which is a part of the heap.
- Strings are stored in the String Pool to save memory.
- Strings are stored in the String Pool because they are immutable.
- Strings are stored in the String Pool because they are used frequently.
- Strings are stored in the String Pool because they are thread-safe.

## String Methods and their functions
- `charAt(int index)` returns the character at the specified index.
- `compareTo(String anotherString)` compares two strings lexicographically.
- `compareToIgnoreCase(String str)` compares two strings lexicographically, ignoring case differences.
- `concat(String str)` concatenates the specified string to the end of this string.
- `contains(CharSequence s)` returns true if and only if this string contains the specified sequence of char values.
- `contentEquals(CharSequence cs)` returns true if and only if this string represents the same sequence of char values as the specified sequence.
- `contentEquals(StringBuffer sb)` returns true if and only if this string represents the same sequence of char values as the specified StringBuffer.
- `copyValueOf(char[] data)` returns a String that represents the character sequence in the array specified.
- `copyValueOf(char[] data, int offset, int count)` returns a String that represents the character sequence in the array specified.
- `endsWith(String suffix)` tests if this string ends with the specified suffix.
- `equals(Object anObject)` compares this string to the specified object.
- `equalsIgnoreCase(String anotherString)` compares this String to another String, ignoring case considerations.
- `format(Locale l, String format, Object... args)` returns a formatted string using the specified locale, format string, and arguments.
- `format(String format, Object... args)` returns a formatted string using the specified format string and arguments.
- `getBytes()` encodes this String into a sequence of bytes using the platform's default charset, storing the result into a new byte array.
- `getBytes(Charset charset)` encodes this String into a sequence of bytes using the given charset, storing the result into a new byte array.
- `getBytes(String charsetName)` encodes this String into a sequence of bytes using the named charset, storing the result into a new byte array.
- `getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)` copies characters from this string into the destination character array.
- `hashCode()` returns a hash code for this string.
- `indexOf(int ch)` returns the index within this string of the first occurrence of the specified character.
- `indexOf(int ch, int fromIndex)` returns the index within this string of the first occurrence of the specified character, starting the search at the specified index.
- `indexOf(String str)` returns the index within this string of the first occurrence of the specified substring.

## String Constructors
- `String()` initializes a newly created String object so that it represents an empty character sequence.
- `String(byte[] bytes)` constructs a new String by decoding the specified array of bytes using the platform's default charset.
- `String(byte[] bytes, Charset charset)` constructs a new String by decoding the specified array of bytes using the specified charset.
- `String(byte[] bytes, int offset, int length)` constructs a new String by decoding the specified subarray of bytes using the platform's default charset.
- `String(byte[] bytes, int offset, int length, Charset charset)` constructs a new String by decoding the specified subarray of bytes using the specified charset.
- `String(byte[] ascii, int hibyte)` Deprecated. This method does not properly convert bytes into characters.
- `String(byte[] ascii, int hibyte, int offset, int count)` Deprecated. This method does not properly convert bytes into characters.
- `String(byte[] bytes, int offset, int length, String charsetName)` constructs a new String by decoding the specified subarray of bytes using the specified charset.
- `String(byte[] bytes, String charsetName)` constructs a new String by decoding the specified array of bytes using the specified charset.
- `String(char[] value)` allocates a new String so that it represents the sequence of characters currently contained in the character array argument.
- `String(char[] value, int offset, int count)` allocates a new String that contains characters from a subarray of the character array argument.
- `String(int[] codePoints, int offset, int count)` Allocates a new String that contains characters from a subarray of the Unicode code point array argument.
- `String(String original)` initializes a newly created String object so that it represents the same sequence of characters as the argument; in other words, the newly created string is a copy of the argument string.
- `String(StringBuffer buffer)` allocates a new string that contains the sequence of characters currently contained in the string buffer argument.
- `String(StringBuilder builder)` allocates a new string that contains the sequence of characters currently contained in the string builder argument.

## String Methods
- `boolean equals(Object anObject)` compares this string to the specified object.
- `boolean equalsIgnoreCase(String anotherString)` compares this String to another String, ignoring case considerations.
- `boolean regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len)` tests if two string regions are equal.
- `boolean regionMatches(int toffset, String other, int ooffset, int len)` tests if two string regions are equal.
- `boolean startsWith(String prefix)` tests if this string starts with the specified prefix.
- `boolean startsWith(String prefix, int toffset)` tests if this string starts with the specified prefix beginning a specified index.
- `byte[] getBytes()` encodes this String into a sequence of bytes using the platform's default charset, storing the result into a new byte array.
- `byte[] getBytes(Charset charset)` encodes this String into a sequence of bytes using the given charset, storing the result into a new byte array.
- `byte[] getBytes(String charsetName)` encodes this String into a sequence of bytes using the named charset, storing the result into a new byte array.
- `char charAt(int index)` returns the character at the specified index.
- `char[] toCharArray()` converts this string to a new character array.
- `CharSequence subSequence(int beginIndex, int endIndex)` returns a new character sequence that is a subsequence of this sequence.
- `int compareTo(String anotherString)` compares two strings lexicographically.
- `int compareToIgnoreCase(String str)` compares two strings lexicographically, ignoring case differences.
- `int indexOf(int ch)` returns the index within this string of the first occurrence of the specified character.
- `int indexOf(int ch, int fromIndex)` returns the index within this string of the first occurrence of the specified character, starting the search at the specified index.
- `int indexOf(String str)` returns the index within this string of the first occurrence of the specified substring.
- `int indexOf(String str, int fromIndex)` returns the index within this string of the first occurrence of the specified substring, starting at the specified index.
- `int lastIndexOf(int ch)` returns the index within this string of the last occurrence of the specified character.
- `int lastIndexOf(int ch, int fromIndex)` returns the index within this string of the last occurrence of the specified character, searching backward starting at the specified index.
- `int lastIndexOf(String str)` returns the index within this string of the rightmost occurrence of the specified substring.
- `int lastIndexOf(String str, int fromIndex)` returns the index within this string of the last occurrence of the specified substring, searching backward starting at the specified index.
- `int length()` returns the length of this string.
- `int offsetByCodePoints(int index, int codePointOffset)` Returns the index within this String that is offset from the given index by codePointOffset code points.
- `int codePointAt(int index)` Returns the character (Unicode code point) at the specified index.
- `int codePointBefore(int index)` Returns the character (Unicode code point) before the specified index.
- `int codePointCount(int beginIndex, int endIndex)` Returns the number of Unicode code points in the specified text range of this String.
- `int hashCode()` returns a hash code for this string.

