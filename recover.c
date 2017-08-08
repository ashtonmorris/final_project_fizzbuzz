 
 #include <stdio.h>
 #include <stdint.h>
 
 const int jpeg= 512;
 
int main (void)
{   
    // ensure that it accepts exact command line argument
    //int argc = 0;
    //if (argc != 1)
   // {
        //fprintf(stderr, "Incorrect # of command line arguments.\n");
        //return 1;
   // }
    
    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "File can not be opened. \n");
        return 1;
    }
    
    uint8_t buf[512];
    
    int counter = 0;
    FILE *fw = NULL;
    
    // Iterate over file contents
    while (fread(buf, jpeg, 1, inptr))
    {
        // Check if the first four bytes are a JPEG signature
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff
            && (buf[3] == 0xe0 || buf[3] == 0xe1))
        {
            // Close the file, if it is opened
            if (fw != NULL)
                fclose(fw);
            
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
                
            // Open a new JPEG file for writing
            fw = fopen(filename, "w");
            
            counter++;
        }
        
        if (fw != NULL)
            fwrite(buf, jpeg, 1, fw);
    }
    
    if (fw != NULL)
        fclose(fw);
    
    fclose(inptr);
 
    return 0;
} 