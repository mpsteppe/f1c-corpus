bool __stdcall sub_5212F0(int a1, float a2, int a3)
{
  int v3; // ebx
  int v4; // edi
  int v6; // esi

  v3 = a3;
  v4 = a1;
  if ( (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a1 + 28))(a1, a3, 4) != 4 )
    return 0;
  if ( (*(_DWORD *)v3 & 0xE0000000) != 0x20000000 || (*(_DWORD *)v3 & 0xFC0000) != 0 )
  {
    *(float *)(v3 + 4) = a2;
  }
  else
  {
    (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v4 + 28))(v4, &a1, 1);
    a1 = (unsigned __int8)a1;
    *(float *)(v3 + 4) = (double)(unsigned __int8)a1 * 0.0001670000056037679 + a2;
  }
  v6 = (*(_DWORD *)v3 >> 8) & 0x3FF;
  return v6 == (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v4 + 28))(v4, v3 + 8, v6);
}
