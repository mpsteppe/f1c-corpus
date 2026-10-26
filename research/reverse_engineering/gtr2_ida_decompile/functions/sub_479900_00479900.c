BOOL __thiscall sub_479900(__int16 *this, int a2, float *a3)
{
  int v4; // esi
  int v5; // ebx
  double v6; // st7
  int *v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = *(_DWORD *)this;
  v5 = 0;
  sub_4796F0((_DWORD *)(*(_DWORD *)this + 113304), &v8, &a2);
  if ( v8 != *(int **)(v4 + 113308) )
    v5 = *((unsigned __int8 *)v8 + 16);
  a2 = this[v5 + 4798];
  v6 = (double)a2 * 0.001;
  *a3 = v6;
  return v6 != 0.0;
}
