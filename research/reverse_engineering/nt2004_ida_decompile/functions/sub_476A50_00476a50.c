int __thiscall sub_476A50(int *this, int a2, int a3, int a4, int a5)
{
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  int *v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h] BYREF

  v6 = 0;
  if ( this[107] > 0 )
  {
    v11 = this + 108;
    do
    {
      v7 = this[94];
      if ( v6 >= v7 && v6 < v7 + this[100] )
      {
        v8 = *v11;
        if ( *v11 >= 0 && v8 < this[107] )
        {
          v9 = (_DWORD *)this[104];
          if ( v8 <= 0 )
          {
LABEL_10:
            if ( v9 )
            {
              if ( *v9 )
              {
                v12 = 0;
                v13 = 0;
                sub_506B70(&v12, &v13, 0);
                if ( v12 > 0 && v13 > 0 )
                  sub_506960(0);
              }
            }
          }
          else
          {
            while ( v9 )
            {
              v9 = (_DWORD *)v9[1];
              if ( --v8 <= 0 )
                goto LABEL_10;
            }
          }
        }
      }
      ++v6;
      ++v11;
    }
    while ( v6 < this[107] );
  }
  (*(void (__thiscall **)(int *, int, int, int, int))(*this + 164))(this, a2, a3, a4, a5);
  return 0;
}
