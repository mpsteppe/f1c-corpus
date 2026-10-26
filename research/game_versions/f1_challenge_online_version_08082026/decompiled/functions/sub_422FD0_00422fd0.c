char __thiscall sub_422FD0(_DWORD *this, const char *a2, int a3)
{
  const char *v3; // edi
  char v5[1024]; // [esp+Ch] [ebp-400h] BYREF

  if ( this[32] )
    v3 = (const char *)this[32];
  else
    v3 = &byte_5EA438;
  if ( !a2 || !sub_588410(v3, &byte_5EA438) )
    return 0;
  strcpy(v5, a2);
  sub_58815F(a2, "%s%s", v3, v5);
  return 1;
}
