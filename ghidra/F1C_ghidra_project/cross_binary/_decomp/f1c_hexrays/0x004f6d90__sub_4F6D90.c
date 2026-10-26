// f1c  0x004f6d90  size=361
int __thiscall sub_4F6D90(int *this, float a2, int a3, int a4, float a5)
{
  int result; // eax
  int v7; // ebx
  float *i; // edi
  int v9; // ecx
  int v10; // edi
  double v11; // st7
  int v12; // ecx
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  int v16; // ebx
  int v17; // ecx
  float v18; // [esp+18h] [ebp-20h]
  float v19; // [esp+18h] [ebp-20h]
  float v20; // [esp+1Ch] [ebp-1Ch]
  float v21; // [esp+1Ch] [ebp-1Ch]
  float v22; // [esp+20h] [ebp-18h]
  float v23; // [esp+34h] [ebp-4h]

  result = *this;
  v7 = 0;
  if ( *this > 0 )
  {
    for ( i = (float *)(this + 1); a2 > (double)i[1] || a2 < (double)*i; i += 3 )
    {
      v9 = *(_DWORD *)(this[16] + 4 * v7);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(v9);
      result = *this;
      if ( ++v7 >= *this )
        return result;
    }
    v10 = v7 + 1;
    if ( v7 + 1 == *this || a2 < (double)*(float *)&this[3 * v10 + 1] )
    {
      v16 = *(_DWORD *)(this[16] + 4 * v7);
      v22 = a2 * *(float *)&this[3 * v10];
      for ( result = (*(int (__thiscall **)(int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v16 + 4))(
                       v16,
                       2,
                       a3,
                       a4,
                       LODWORD(a5),
                       LODWORD(v22),
                       0); v10 < *this; ++v10 )
      {
        v17 = *(_DWORD *)(this[16] + 4 * v10);
        (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 8))(v17);
        result = *this;
      }
    }
    else
    {
      v11 = *(float *)&this[3 * v10 + 1];
      v12 = *(_DWORD *)(this[16] + 4 * v7);
      v23 = (a2 - v11) / (*(float *)&this[3 * v7 + 2] - v11);
      v20 = a2 * *(float *)&this[3 * v10];
      v18 = sqrt(1.0 - v23) * a5;
      (*(void (__thiscall **)(int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 4))(
        v12,
        2,
        a3,
        a4,
        LODWORD(v18),
        LODWORD(v20),
        0);
      v13 = *(_DWORD *)(this[16] + 4 * v10);
      v14 = v7 + 2;
      v21 = a2 * *(float *)&this[3 * v7 + 6];
      v19 = sqrt(v23) * a5;
      for ( result = (*(int (__thiscall **)(int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v13 + 4))(
                       v13,
                       2,
                       a3,
                       a4,
                       LODWORD(v19),
                       LODWORD(v21),
                       0); v14 < *this; ++v14 )
      {
        v15 = *(_DWORD *)(this[16] + 4 * v14);
        (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 8))(v15);
        result = *this;
      }
    }
  }
  return result;
}
