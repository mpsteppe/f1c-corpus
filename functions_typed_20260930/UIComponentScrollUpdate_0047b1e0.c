int __thiscall UIComponentScrollUpdate(int this)
{
  int v2; // eax
  double v3; // st7
  bool v4; // cc
  int result; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // [esp-4h] [ebp-14h]
  float v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 44))(this, 1);
  DualFieldRead(*(_DWORD **)(this + 64), &v11, &v10);
  v9 = FloatFieldAccessor((float *)*(_DWORD *)(this + 64)) + *(float *)(this + 264);
  *(float *)(this + 264) = v9;
  switch ( *(_DWORD *)(this + 260) )
  {
    case 1:
      v2 = MenuItemLayoutCalculator((_DWORD *)this, v11, v10);
      v3 = *(float *)(this + 264);
      *(_DWORD *)(this + 228) = v2;
      if ( v3 <= 0.125 )
        goto LABEL_18;
      v4 = v10 <= *(_DWORD *)(this + 252) + *(_DWORD *)(this + 4);
      *(float *)(this + 264) = *(float *)(this + 264) - 0.125;
      if ( v4 )
        BoundedCounterUpdate((_DWORD *)this, -1);
      if ( v10 < *(_DWORD *)(this + 8) - *(_DWORD *)(this + 252) )
        goto LABEL_18;
      BoundedCounterUpdate((_DWORD *)this, 1);
      result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this);
      break;
    case 2:
      if ( v9 <= 0.125 )
        goto LABEL_18;
      *(float *)(this + 264) = v9 - 0.125;
      BoundedCounterUpdate((_DWORD *)this, -1);
      result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this);
      break;
    case 3:
      if ( v9 <= 0.125 )
        goto LABEL_18;
      *(float *)(this + 264) = v9 - 0.125;
      BoundedCounterUpdate((_DWORD *)this, 1);
      result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this);
      break;
    case 4:
      v6 = *(_DWORD *)(this + 276);
      v7 = v10 - *(_DWORD *)(this + 284);
      *(_DWORD *)(this + 272) = v7;
      if ( v7 >= 0 )
      {
        if ( v7 > v6 )
          *(_DWORD *)(this + 272) = v6;
        sub_47BE00(this);
        result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this);
      }
      else
      {
        *(_DWORD *)(this + 272) = 0;
        sub_47BE00(this);
        result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this);
      }
      break;
    case 5:
      if ( v9 > 0.25 )
      {
        v8 = v10;
        *(float *)(this + 264) = v9 - 0.25;
        sub_47BB40((_DWORD *)this, v8);
      }
      goto LABEL_18;
    default:
LABEL_18:
      result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 84))(this);
      break;
  }
  return result;
}

