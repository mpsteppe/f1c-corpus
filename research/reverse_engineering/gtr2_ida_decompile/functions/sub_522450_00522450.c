int __thiscall sub_522450(_DWORD *this, int a2, int a3, float a4, float a5)
{
  int *v5; // eax
  int v6; // edi
  int v7; // ebp
  double v8; // st7
  int v9; // eax
  int v10; // esi
  int *v11; // eax
  int v12; // edi
  int v13; // esi
  int v15; // [esp+18h] [ebp-408h]
  _DWORD *v16; // [esp+1Ch] [ebp-404h]
  _BYTE v17[1024]; // [esp+20h] [ebp-400h] BYREF

  v5 = (int *)this[471];
  v6 = 0;
  v16 = this;
  v15 = 0;
  this[473] = v5;
  if ( v5 )
  {
    v7 = *v5;
    if ( *v5 )
    {
      while ( 1 )
      {
        v8 = *(float *)v7;
        if ( v8 > a5 )
          break;
        v9 = this[473];
        v10 = v7;
        if ( v9 )
          this[473] = *(_DWORD *)(v9 + 4);
        v11 = (int *)this[473];
        if ( v11 )
          v7 = *v11;
        else
          v7 = 0;
        if ( v8 >= a4 )
        {
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 52))(a2, *(_DWORD *)(v10 + 4));
          if ( v7 )
          {
            v12 = *(_DWORD *)(v7 + 4) - *(_DWORD *)(v10 + 4);
          }
          else
          {
            if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a2 + 48))(a2) )
              return v6;
            v12 = sub_614040(a2) - *(_DWORD *)(v10 + 4);
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 52))(a2, *(_DWORD *)(v10 + 4));
          }
          while ( v12 > 0 )
          {
            v13 = 1024;
            if ( v12 <= 1024 )
              v13 = v12;
            (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 28))(a2, v17, v13);
            if ( (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a3 + 24))(a3, v17, v13) == v13 )
            {
              v12 -= v13;
              v15 += v13;
            }
          }
          v6 = v15;
          this = v16;
        }
        if ( !v7 )
          return v6;
      }
    }
  }
  return v6;
}
