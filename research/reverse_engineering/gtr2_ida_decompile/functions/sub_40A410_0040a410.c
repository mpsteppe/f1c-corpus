_DWORD *__thiscall sub_40A410(_DWORD *this, char a2, float a3, int a4)
{
  int v5; // ebx
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  int v9; // esi
  double v10; // st7
  _DWORD *v12; // [esp+Ch] [ebp-8h]
  float v13; // [esp+10h] [ebp-4h]
  float v14; // [esp+18h] [ebp+4h]
  float v15; // [esp+1Ch] [ebp+8h]

  v5 = 0;
  v6 = 0;
  v12 = 0;
  v14 = (float)(1 << a2);
  v13 = a3 * a3;
  if ( (int)this[19] <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = this[18];
    v8 = *(_DWORD *)(v7 + v5);
    v9 = v5 + v7;
    if ( !v8 || a4 && (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 28))(v8) == 2 )
      break;
    v10 = (double)(1 << *(_DWORD *)(v9 + 4));
    v15 = *(float *)(v9 + 8) * *(float *)(v9 + 8);
    if ( v10 * v13 < v15 * v14 )
    {
      v14 = v10;
      v12 = (_DWORD *)v9;
      v13 = *(float *)(v9 + 8) * *(float *)(v9 + 8);
    }
    ++v6;
    v5 += 20;
    if ( v6 >= this[19] )
      goto LABEL_10;
  }
  v12 = (_DWORD *)v9;
LABEL_10:
  if ( !v12 )
    return 0;
  if ( *v12 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v12 + 8))(*v12);
  return v12;
}
