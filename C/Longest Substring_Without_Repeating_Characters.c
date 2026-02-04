int lengthOfLongestSubstring(char* s) {
    int charIndex[256];  // Array to store last index of each character
    for (int i = 0; i < 256; i++) {
        charIndex[i] = -1;
    }
    
    int maxLength = 0;
    int left = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char currentChar = (unsigned char)s[right];
        
        // If character is already in the window, move left pointer
        if (charIndex[currentChar] >= left) {
            left = charIndex[currentChar] + 1;
        }
        
        // Update the character's latest position
        charIndex[currentChar] = right;
        
        // Update max length
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}