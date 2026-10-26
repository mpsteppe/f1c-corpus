double sub_4E4DE0()
{
  return sqrt(
           *((float *)dword_91E07C + 4003) * *((float *)dword_91E07C + 4003)
         + *((float *)dword_91E07C + 4004) * *((float *)dword_91E07C + 4004)
         + *((float *)dword_91E07C + 4005) * *((float *)dword_91E07C + 4005))
       * 3.5999999;
}
