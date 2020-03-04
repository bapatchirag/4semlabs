def constructShift(pattern):
	shiftTable = {}
	count = 0
	
	for c in reversed(pattern):
		if count == 0:
			count += 1
			continue
		
		if c not in shiftTable.keys():
			shiftTable[c] = count
			count += 1
			
	for c in "abcdefghijklmnopqrstuvwxyz ":
		if c not in shiftTable.keys():
			shiftTable[c] = len(pattern)
			
	return shiftTable
	
def matching(text, pattern):
	m = len(pattern)
	n = len(text)
	
	shiftTable = constructShift(pattern)
	
	lastCharIndex = m - 1
	while lastCharIndex < n:
		correctChars = 0
		while correctChars < m:
			if pattern[m - 1 - correctChars] != text[lastCharIndex - correctChars]:
				break
			correctChars += 1
			
		if correctChars == m:
			return lastCharIndex - m + 1
		else:
			lastCharIndex += shiftTable[text[lastCharIndex]]
			
	return -1
	
# Main script starts

text = input("Enter text: ")
pattern = input("Enter pattern to be searched for: ")
firstMatchIndex = matching(text, pattern)

if firstMatchIndex == -1:
	print("Match not found")
	
else:
	print("Match found at index " + str(firstMatchIndex))
