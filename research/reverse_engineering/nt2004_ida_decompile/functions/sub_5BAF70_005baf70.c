void __fastcall sub_5BAF70(int a1, int a2, char *a3, int a4)
{
  char *v5; // eax
  char v6; // dl
  _BYTE v7[68]; // [esp+8h] [ebp-44h] BYREF

  if ( a4 >= 1 && a4 <= 65 )
  {
    v5 = a3;
    if ( !a3[a4 - 1] )
    {
      do
      {
        v6 = *v5;
        v5[v7 - a3] = *v5;
        ++v5;
      }
      while ( v6 );
      strlen((const char *)(a1 + 68));
      sub_5BB0F0(v7, a4 - 1);
      sub_5BB000(a2 + *(_DWORD *)(a2 + 2048));
      *(_DWORD *)(a2 + 2048) += strlen((const char *)(*(_DWORD *)(a2 + 2048) + a2)) + 1;
    }
  }
}
