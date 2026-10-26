void __userpurge sub_573480(int a1@<ecx>, int a2@<edi>, int a3)
{
  char v4; // al
  int v5; // ecx
  int v6; // [esp+0h] [ebp-8h]

  v4 = *(_BYTE *)(a1 + 17303);
  *(_BYTE *)(a1 + 17301) = 0;
  if ( !v4 )
  {
    if ( !a3 )
    {
      *(_DWORD *)(a1 + 17328) = 0;
      *(_DWORD *)(a1 + 17324) = 0;
      *(_DWORD *)(a1 + 17304) = 0;
      return;
    }
    if ( *(float *)(a1 + 17324) <= 0.0 )
    {
      v5 = a1 + 8;
      if ( a3 <= *(_DWORD *)(a1 + 17304) )
      {
        sub_58C790(v5);
        *(_DWORD *)(a1 + 17324) = *(_DWORD *)(a1 + 17320);
      }
      else
      {
        sub_58EC30(v5, a2, v6);
        *(_DWORD *)(a1 + 17324) = *(_DWORD *)(a1 + 17316);
        if ( a3 == 1 && !*(_DWORD *)(a1 + 17304) )
        {
          *(_DWORD *)(a1 + 17328) = 1;
          *(_DWORD *)(a1 + 17304) = 0;
          *(_BYTE *)(a1 + 17301) = 1;
          return;
        }
      }
      *(_DWORD *)(a1 + 17328) = a3;
      *(_DWORD *)(a1 + 17304) = 0;
    }
  }
}
