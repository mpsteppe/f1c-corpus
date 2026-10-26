_DWORD *__thiscall sub_55C070(int *this, int a2, char a3)
{
  _DWORD *result; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // ebx
  int v10; // eax
  int *v11; // esi
  _DWORD *v12; // eax
  int v13; // edx
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // [esp+10h] [ebp-50h] BYREF
  int v18; // [esp+14h] [ebp-4Ch] BYREF
  int v19; // [esp+18h] [ebp-48h] BYREF
  int v20; // [esp+1Ch] [ebp-44h] BYREF
  int v21[16]; // [esp+20h] [ebp-40h] BYREF
  int v22; // [esp+64h] [ebp+4h]

  result = StructInitWithDefaultValues(v21);
  if ( (*(_BYTE *)(a2 + 36) & 4) == 0 )
  {
    sub_5424E0(*(_DWORD **)(a2 + 12), &v17, &v18, &v19, &v20);
    v5 = this[1088];
    v6 = *(_DWORD *)(a2 + 12);
    v19 += v17;
    v20 += v18;
    result = (_DWORD *)(*(int (__stdcall **)(int, int, int *, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 144))(
                         v5,
                         1,
                         &v17,
                         1,
                         *(_DWORD *)(v6 + 124),
                         0,
                         0);
    *this = (int)result;
  }
  if ( (a3 & 0x10) == 0 )
  {
    v21[8] = 5;
    MultiFieldSetterDispatchingTo7SubSetters(this + 1118, v21, 0);
    sub_554790(this, 256, 0, 0);
    v7 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 7, 0);
    v8 = this[1267];
    *this = v7;
    v9 = *(_DWORD **)(a2 + 24);
    v10 = v9[78];
    if ( v10 != v8 )
    {
      this[1267] = v10;
      LogSessionEvent((char *)v9[78]);
    }
    v22 = 0;
    if ( (int)v9[70] > 0 )
    {
      v11 = (int *)(v9[71] + 28);
      do
      {
        if ( (v9[5] & 0x1000000) == 0 && !v9[79] )
        {
          v12 = (_DWORD *)BufferLockAllocate(this, (_DWORD *)*v11, 160, v11[4], *(v11 - 5));
          v13 = *(v11 - 5);
          v14 = (_DWORD *)*(v11 - 4);
          v11[1] = (int)v12;
          if ( v13 > 0 )
          {
            do
            {
              *v12 = *v14;
              v12[1] = v14[1];
              v12[2] = v14[2];
              v12 += 16;
              v14 += 12;
              --v13;
            }
            while ( v13 );
          }
          ArithmeticComparison_0f90(this, *v11);
        }
        PropertyValueSetterWithRefreshOnChange(this, (_DWORD *)*v11);
        *this = (*(int (__stdcall **)(int, _DWORD, int))(*(_DWORD *)this[1088] + 340))(
                  this[1088],
                  *(_DWORD *)(v11[2] + 24),
                  v11[4]);
        v15 = *(v11 - 3);
        if ( (BYTE1(v9[5]) & 0x80u) == 0 )
          v16 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, int, int))(*(_DWORD *)this[1088] + 284))(
                  this[1088],
                  5,
                  0,
                  *(v11 - 5),
                  v11[5],
                  v15 - 2);
        else
          v16 = (*(int (__stdcall **)(int, int, _DWORD, _DWORD, int, int))(*(_DWORD *)this[1088] + 284))(
                  this[1088],
                  4,
                  0,
                  *(v11 - 5),
                  v11[5],
                  v15 / 3);
        *this = v16;
        v11 += 16;
        ++v22;
      }
      while ( v22 < v9[70] );
    }
    v9[5] |= 0x1000000u;
    result = (_DWORD *)(*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 7, this[1262]);
    *this = (int)result;
  }
  return result;
}

