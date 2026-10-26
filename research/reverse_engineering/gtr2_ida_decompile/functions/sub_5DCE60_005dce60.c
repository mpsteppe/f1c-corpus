int __thiscall sub_5DCE60(float *this)
{
  return (unsigned __int64)(this[60] * 255.0)
       - (((unsigned int)(unsigned __int64)(this[59] * -255.0)
         + ((unsigned int)(unsigned __int64)(this[58] * -255.0) << 8)) << 8);
}
