int __thiscall HitTest(int this)
{
  int result; // eax
  _DWORD *v3; // ecx
  int v4; // edi
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int i; // ecx
  int v11; // [esp+Ch] [ebp-8h] BYREF
  int v12; // [esp+10h] [ebp-4h] BYREF

  DualFieldRead(*(_DWORD **)(this + 64), &v12, &v11);
  result = *(_DWORD *)(this + 356);
  *(_DWORD *)(this + 364) = result;
  if ( result )
  {
    v3 = *(_DWORD **)result;
    if ( *(_DWORD *)result )
    {
      v4 = v11;
      v5 = v12;
      while ( 1 )
      {
        v6 = *(_DWORD *)(this + 12) + *v3;
        v7 = *(_DWORD *)(this + 4) + v3[1];
        if ( v5 < v6 + 20 && v5 > v6 - 20 )
        {
          result = v7 + 20;
          if ( v4 < v7 + 20 && v4 > v7 - 20 )
            break;
        }
        v8 = *(_DWORD *)(this + 364);
        if ( v8 )
          *(_DWORD *)(this + 364) = *(_DWORD *)(v8 + 4);
        result = *(_DWORD *)(this + 364);
        if ( result )
        {
          v3 = *(_DWORD **)result;
          if ( *(_DWORD *)result )
            continue;
        }
        return result;
      }
      v9 = *(_DWORD *)(this + 364);
      i = -1;
      if ( v9 )
      {
        result = *(_DWORD *)(this + 356);
        for ( i = 0; result; ++i )
        {
          if ( result == v9 )
            break;
          result = *(_DWORD *)(result + 4);
        }
      }
      *(_DWORD *)(this + 344) = i;
    }
  }
  return result;
}
