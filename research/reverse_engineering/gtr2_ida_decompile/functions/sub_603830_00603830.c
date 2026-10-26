int __thiscall sub_603830(void *this, int *a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // edx
  int v7; // edi
  int *v8; // ecx
  int v9; // [esp-4h] [ebp-10h]
  char v10; // [esp+0h] [ebp-Ch]

  result = *a2;
  v6 = *a2 & 0x10;
  if ( v6 )
  {
    switch ( a5 )
    {
      case 0:
        v7 = 0;
        break;
      case 1:
        v7 = 1;
        break;
      case 2:
        v7 = 2;
        break;
      case 3:
        v7 = 3;
        break;
      case 4:
        v7 = 4;
        break;
      case 5:
        v7 = 5;
        break;
      default:
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v7 = a3;
  }
  if ( a4 )
    result = a4;
  if ( (result & 4) == 0 )
  {
    if ( (result & 8) != 0 )
      return result;
    if ( (result & 1) != 0 )
    {
      v8 = a2;
      v9 = 1;
      if ( v6 )
      {
LABEL_19:
        result = sub_5E7150(v8, v9);
        if ( !result )
          return result;
        goto LABEL_20;
      }
      result = sub_5E7120(a2, 1);
      if ( !result )
        return result;
    }
    else
    {
      if ( (result & 2) == 0 )
        return sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Invalid source surface specified for UnlockSurface", v10);
      if ( v6 )
      {
        result = sub_5E7150(a2, 2);
        if ( !result )
          return result;
LABEL_20:
        result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)result + 80))(result, v7, a3);
        a2[4] = 0;
        return result;
      }
      result = sub_5E7120(a2, 2);
      if ( !result )
        return result;
    }
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 56))(result);
    a2[4] = 0;
    return result;
  }
  v8 = a2;
  v9 = 4;
  if ( v6 )
    goto LABEL_19;
  result = sub_5E7150(a2, 4);
  if ( result )
  {
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)result + 80))(result, a3);
    a2[4] = 0;
  }
  return result;
}
