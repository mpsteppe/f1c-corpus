// Function: uflow @ 00598cdc
// Size (bytes): 29


/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::uflow(void)
   
   Library: Visual Studio 2003 Release */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::uflow
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = (**(code **)(*(int *)this + 0x10))();
  if (iVar1 == -1) {
    return -1;
  }
  pbVar2 = (byte *)_Gninc(this);
  return (uint)*pbVar2;
}


