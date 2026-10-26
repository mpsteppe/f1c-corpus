int __thiscall sub_58BCF0(void *this, int a2, float a3, float a4, int a5, int a6, float a7)
{
  int result; // eax
  int v9; // ebx
  int i; // edi
  float v11; // [esp+0h] [ebp-14h]
  float v12; // [esp+0h] [ebp-14h]
  float v13; // [esp+20h] [ebp+Ch]

  if ( a4 > (double)*(float *)this )
  {
    if ( a4 < (double)*((float *)this + 1) )
    {
      v13 = (a4 - *(float *)this) * *((float *)this + 2);
      v11 = (1.0 - v13) * a7;
      sub_58BB10((int *)this + 3, *((_DWORD *)this + 59), a2, a3, a5, a6, v11);
      v12 = v13 * a7;
      return sub_58BB10((int *)this + 24, *((_DWORD *)this + 59) + 20, a2, a3, a5, a6, v12);
    }
    else
    {
      sub_58BC80((int *)this + 3, *((_DWORD *)this + 59));
      return sub_58BB10((int *)this + 24, *((_DWORD *)this + 59) + 20, a2, a3, a5, a6, a7);
    }
  }
  else
  {
    sub_58BB10((int *)this + 3, *((_DWORD *)this + 59), a2, a3, a5, a6, a7);
    result = *((_DWORD *)this + 24);
    v9 = *((_DWORD *)this + 59) + 20;
    for ( i = 0; i < result; ++i )
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v9 + 4 * i) + 8))(*(_DWORD *)(v9 + 4 * i));
      result = *((_DWORD *)this + 24);
    }
  }
  return result;
}
