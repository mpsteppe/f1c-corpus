int __thiscall sub_4DCA80(void *this)
{
  int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  float v4; // [esp+0h] [ebp-20h]
  float v5; // [esp+0h] [ebp-20h]
  float v6; // [esp+0h] [ebp-20h]
  float v7; // [esp+4h] [ebp-1Ch]
  float v8; // [esp+4h] [ebp-1Ch]
  float v9; // [esp+4h] [ebp-1Ch]
  float v10; // [esp+4h] [ebp-1Ch]
  float v11; // [esp+8h] [ebp-18h]
  float v12; // [esp+8h] [ebp-18h]
  float v13; // [esp+8h] [ebp-18h]
  float v14; // [esp+8h] [ebp-18h]

  if ( *(_DWORD *)this )
  {
    v11 = (float)*((int *)this + 4);
    v7 = (float)*((int *)this + 3);
    v3 = (float)*((int *)this + 2);
    sub_553650(0, v3, v7, v11, 0.0, 0.0, *((_DWORD *)this + 7));
    v12 = (float)*((int *)this + 4);
    v8 = (float)(*((_DWORD *)this + 6) + *((_DWORD *)this + 3));
    v4 = (float)*((int *)this + 2);
    sub_553650(1, v4, v8, v12, 0.0, *((float *)this + 9), *((_DWORD *)this + 7));
    v13 = (float)*((int *)this + 4);
    v9 = (float)(*((_DWORD *)this + 6) + *((_DWORD *)this + 3));
    v5 = (float)(*((_DWORD *)this + 5) + *((_DWORD *)this + 2));
    sub_553650(2, v5, v9, v13, *((float *)this + 8), *((float *)this + 9), *((_DWORD *)this + 7));
    v14 = (float)*((int *)this + 4);
    v10 = (float)*((int *)this + 3);
    v6 = (float)(*((_DWORD *)this + 5) + *((_DWORD *)this + 2));
    return sub_553650(3, v6, v10, v14, *((float *)this + 8), 0.0, *((_DWORD *)this + 7));
  }
  return result;
}

