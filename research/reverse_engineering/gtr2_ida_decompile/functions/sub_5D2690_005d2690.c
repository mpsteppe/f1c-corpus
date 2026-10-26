void __userpurge sub_5D2690(int a1@<ecx>, int a2@<ebx>, int a3@<edi>, double a4)
{
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  float v13; // [esp+4h] [ebp-8h]

  if ( *(_DWORD *)(a1 + 16) )
    sub_5D2690(a4);
  v5 = *(_DWORD *)(a1 + 8);
  if ( !v5
    || (v6 = *(_DWORD *)(v5 + 48), v6 == -1)
    || *(_DWORD *)(v5 + 44) < v6
    || !sub_5C1530(*(_DWORD **)(a1 + 4))
    || (v7 = (_DWORD *)sub_5C1530(*(_DWORD **)(a1 + 4)), (v8 = sub_5D1CB0(v7)) == 0)
    || v8 != *(_DWORD **)(a1 + 8) )
  {
    v9 = *(_DWORD *)(a1 + 8);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 48);
      if ( v10 != -1 && *(_DWORD *)(v9 + 44) >= v10 && !*(_BYTE *)(v9 + 81) )
      {
        v13 = *(double *)(v9 + 16);
        (*(void (__cdecl **)(int, _DWORD))(**(_DWORD **)(a1 + 4) + 8))(v9, LODWORD(v13));
      }
    }
    v11 = *(_DWORD *)(a1 + 8);
    if ( !*(_BYTE *)(v11 + 82) )
    {
      if ( *(float *)(v11 + 32) > 0.0 )
      {
        if ( *(float *)(v11 + 32) >= 1.0 && *(_DWORD *)(a1 + 16) && !*(_BYTE *)(v11 + 83) && *(_DWORD *)(v11 + 72) != 1 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v11 + 60) + 24))(*(_DWORD *)(v11 + 60)) )
          {
            sub_5D2650(*(_DWORD *)(a1 + 16), a3);
            sub_5C40C0();
          }
          else
          {
            v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a1 + 8) + 60) + 4))(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 60));
            sub_5D1C10(a1, a2, a1, v12);
          }
        }
      }
      else
      {
        sub_5C40C0();
      }
    }
  }
}
