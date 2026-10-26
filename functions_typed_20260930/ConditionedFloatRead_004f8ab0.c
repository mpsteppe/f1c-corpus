double __thiscall sub_4F8AB0(char *this, int a2)
{
  float *v2; // eax

  v2 = (float *)&this[32 * a2];
  if ( *((_BYTE *)v2 + 180) )
    return v2[47];
  else
    return 0.0;
}

