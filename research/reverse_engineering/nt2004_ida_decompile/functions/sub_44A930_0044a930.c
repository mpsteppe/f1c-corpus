double __thiscall sub_44A930(char *this)
{
  return *(float *)this * *(float *)this
       + *(double *)(this + 4) * *(double *)(this + 4)
       + *((float *)this + 3) * *((float *)this + 3);
}
