// Function: _Gninc @ 00599475
// Size (bytes): 16


/* Library Function - Single Match
    protected: char * __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::_Gninc(void)
   
   Library: Visual Studio 2003 Release */

char * __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Gninc
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  char *pcVar1;
  
  **(int **)(this + 0x2c) = **(int **)(this + 0x2c) + -1;
  pcVar1 = (char *)**(int **)(this + 0x1c);
  **(int **)(this + 0x1c) = (int)(pcVar1 + 1);
  return pcVar1;
}


