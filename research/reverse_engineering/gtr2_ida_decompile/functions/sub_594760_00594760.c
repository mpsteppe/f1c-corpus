int __thiscall sub_594760(int *this, float a2)
{
  int v3; // ebp
  int result; // eax
  int v5; // ebp
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // ebx
  int j; // esi
  float v13; // [esp+0h] [ebp-54h]
  unsigned int v14; // [esp+Ch] [ebp-48h] BYREF
  int i; // [esp+10h] [ebp-44h]
  _DWORD v16[16]; // [esp+14h] [ebp-40h]
  int v17; // [esp+58h] [ebp+4h]

  v13 = a2 * 255.0;
  v3 = sub_4015C0(v13);
  result = this[4];
  v5 = 65793 * v3;
  if ( result != v5 )
  {
    this[4] = v5;
    v6 = *this;
    result = 0;
    v17 = 0;
    if ( v6 )
    {
      v16[0] = v6;
      v17 = 1;
    }
    for ( i = 0; i < v17; ++i )
    {
      v7 = v16[result];
      v8 = *(_DWORD *)(v7 + 544);
      v9 = (_DWORD *)(v7 + 532);
      if ( v8 > 0 )
      {
        v10 = (_DWORD *)*v9;
        if ( v10 )
        {
          if ( *v10 )
          {
            v11 = sub_5EA5B0(*v10);
            for ( j = 0; j < v11; ++j )
            {
              sub_5EC580(j, &v14);
              v14 = v5 | v14 & 0xFF000000;
              sub_5EC5A0(j, v14);
            }
          }
        }
      }
      result = i + 1;
    }
  }
  return result;
}
