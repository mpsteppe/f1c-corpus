int __stdcall sub_4B2C70(int a1, int a2, float *a3, _DWORD *a4)
{
  int result; // eax
  int v5; // esi
  int v6; // edi
  double v7; // st7
  int v8; // esi
  float v9; // [esp+10h] [ebp+4h]

  result = 1;
  if ( a1 && a2 )
  {
    v5 = *(_DWORD *)(a1 + 20848);
    v9 = sub_51CA30(a1 + 84);
    v6 = *(_DWORD *)(a2 + 20848);
    v7 = sub_51CA30(a2 + 84);
    *a3 = 0.0;
    *a4 = 0;
    if ( v5 == v6 )
    {
      result = 0;
      *a3 = v9 - v7;
    }
    else if ( v5 <= v6 )
    {
      return 1;
    }
    else if ( v6 + 1 == v5 && v9 < v7 )
    {
      result = 0;
      *a3 = flt_6290DC - v7 + v9;
    }
    else
    {
      v8 = v5 - v6;
      result = 0;
      if ( v9 < v7 )
        --v8;
      *a4 = v8;
    }
  }
  return result;
}
