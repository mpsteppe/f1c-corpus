int __usercall sub_564860@<eax>(int a1@<ebx>)
{
  int v1; // ebx
  int i; // edi
  int j; // edi
  int v5; // [esp+0h] [ebp-48h] BYREF
  char v6[4]; // [esp+4h] [ebp-44h] BYREF
  char Buffer[64]; // [esp+8h] [ebp-40h] BYREF

  if ( *(_DWORD *)dword_B640C8 == 6 && *((float *)dword_91E07C + 4858) == 0.0 && sub_42FE70(&dword_B640C0) )
  {
    sprintf(Buffer, "--/--");
  }
  else
  {
    v5 = a1;
    if ( *(_DWORD *)dword_B72314 == 7 )
    {
      v1 = 0;
      for ( i = 0; i < dword_757C10; ++i )
      {
        if ( !(unsigned __int8)sub_523BD0(dword_BE1210, *(_DWORD *)(*(&dword_91E088 + i) + 22468)) )
          ++v1;
      }
    }
    else if ( *(_DWORD *)dword_B72314 == 8 )
    {
      v1 = 0;
      for ( j = 0; j < dword_757C10; ++j )
      {
        if ( !(unsigned __int8)sub_524300() )
          ++v1;
      }
    }
    else
    {
      v1 = dword_757C10;
    }
    sprintf(v6, "%02d/%02d", *((_DWORD *)dword_91E07C + 4831), v1);
  }
  sub_562B70((int)Buffer, 232, 17, 16688384, 1, 3, 0.64999998, 0.64999998);
  sub_4E56A0(&unk_B6E79C, COERCE_FLOAT(Buffer), 64);
  sub_562B70((int)Buffer, 232, 70, 16688384, 1, 3, 0.44999999, 0.44999999);
  ((void (__thiscall *)(void *, char *, int))loc_4E58A0)(&unk_B6E79C, Buffer, 64);
  sub_562B70((int)&v5, 232, 102, 16688384, 1, 3, 0.44999999, 0.44999999);
  return sub_564720();
}
