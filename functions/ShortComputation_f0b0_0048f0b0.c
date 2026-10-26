char __thiscall ShortComputation_f0b0(int this, int a2, int a3, int a4)
{
  char result; // al
  int v5; // edi
  int v7; // eax
  bool v8; // cc
  int v10; // eax
  int v11; // esi
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp-14h] [ebp-1Ch]
  int v18; // [esp+4h] [ebp-4h]
  int v19; // [esp+10h] [ebp+8h]
  int v20; // [esp+14h] [ebp+Ch]

  result = a2;
  if ( a2 )
  {
    result = *(_BYTE *)(this + 380);
    if ( result )
    {
      v5 = *(_DWORD *)(this + 228);
      if ( v5 )
      {
        v7 = *(_DWORD *)(this + 288);
        v8 = a3 < v7;
        v18 = a3;
        v19 = a4;
        if ( v8 )
        {
          v20 = v7 - a3;
          v18 = *(_DWORD *)(this + 288);
        }
        else
        {
          v20 = 0;
        }
        v10 = *(_DWORD *)(this + 320);
        if ( a4 >= v10 - 10 )
        {
          v11 = 0;
        }
        else
        {
          v11 = v10 - a4;
          v19 = *(_DWORD *)(this + 320);
        }
        v12 = *(_DWORD *)(v5 + 28);
        v13 = *(_DWORD *)(this + 292);
        if ( v12 + a3 > v13 )
          v12 = v13 - a3;
        v14 = *(_DWORD *)(this + 324);
        if ( *(_DWORD *)(*(_DWORD *)(this + 228) + 32) + a4 <= v14 + 10 )
          v15 = *(_DWORD *)(*(_DWORD *)(this + 228) + 32);
        else
          v15 = v14 - a4;
        v17 = v15;
        v16 = GlobalAccessor_5150();
        return F_10ParamForwarder(a2, v20, v11, v16, v18, v19, v12, v17, 0, 0);
      }
    }
  }
  return result;
}
