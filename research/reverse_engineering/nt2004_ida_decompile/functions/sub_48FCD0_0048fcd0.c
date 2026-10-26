int __thiscall sub_48FCD0(_DWORD *this)
{
  const char *v2; // eax
  char v3[32]; // [esp+Ch] [ebp-70h] BYREF
  char Buffer[80]; // [esp+2Ch] [ebp-50h] BYREF

  if ( this[69] == 599 )
  {
    if ( sub_4AF0A0(this) - 1 >= *(int *)dword_7689CC )
    {
      v2 = (const char *)sub_49D690(*(_DWORD *)dword_7689CC);
      sprintf(v3, "%s", v2);
      sub_49EC60(v3);
    }
  }
  else if ( this[69] == 600 )
  {
    sprintf(Buffer, "%.3f", *(float *)&dword_75CBBC);
    sub_49EC60(Buffer);
    return 0;
  }
  return 0;
}
