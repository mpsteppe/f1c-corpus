int __fastcall sub_565D50(LPVOID ***a1)
{
  LPVOID **v1; // esi
  LPVOID **v2; // ebp
  LPVOID *v3; // edi
  int result; // eax
  LPVOID ***v5; // [esp+4h] [ebp-4h]

  v1 = *a1;
  v5 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = v1;
      v1 = (LPVOID **)v1[1];
      if ( *((_BYTE *)v2 + 8) )
      {
        v3 = *v2;
        if ( *v2 )
        {
          if ( v3[81] )
            FreeWrapper_7bcf(v3[81]);
          FreeWrapper_7bcf(v3);
        }
      }
      result = FreeWrapper_7bcf(v2);
    }
    while ( v1 );
    a1 = v5;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
