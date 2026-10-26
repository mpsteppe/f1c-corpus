int __thiscall sub_4582A0(float *this, float a2)
{
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int *v6; // eax
  int v7; // eax
  int result; // eax
  int v9; // ecx
  int v10; // [esp+4h] [ebp-1Ch]
  _DWORD v11[3]; // [esp+8h] [ebp-18h] BYREF
  _BYTE v12[4]; // [esp+14h] [ebp-Ch] BYREF
  _BYTE v13[4]; // [esp+18h] [ebp-8h] BYREF
  _BYTE v14[4]; // [esp+1Ch] [ebp-4h] BYREF

  if ( this[2] > 0.0 )
  {
    v3 = *(_DWORD *)(*(_DWORD *)this + 544);
    v4 = 0;
    *(float *)&v10 = fmod(a2 + this[5], this[2]);
    while ( v4 < v3 )
    {
      v5 = v4;
      if ( v4 >= 0 && v4 < *(_DWORD *)(*(_DWORD *)this + 544) )
      {
        v6 = *(int **)(*(_DWORD *)this + 532);
        if ( v4 <= 0 )
        {
LABEL_8:
          if ( v6 )
          {
            v7 = *v6;
            goto LABEL_11;
          }
        }
        else
        {
          while ( v6 )
          {
            v6 = (int *)v6[1];
            if ( --v5 <= 0 )
              goto LABEL_8;
          }
        }
      }
      v7 = 0;
LABEL_11:
      sub_5F1530(v7, *((_DWORD *)this + 3), v10);
      ++v4;
    }
  }
  result = sub_5DA840(v12, v13, v14, 0);
  v9 = *((_DWORD *)this + 1);
  memset(v11, 0, sizeof(v11));
  if ( v9 )
    result = (*(int (__thiscall **)(int, int, _BYTE *, _DWORD *, int, int, _DWORD))(*(_DWORD *)v9 + 4))(
               v9,
               2,
               v12,
               v11,
               dword_B70948,
               1065353216,
               0);
  this[6] = a2;
  return result;
}
