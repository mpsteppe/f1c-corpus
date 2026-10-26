int __thiscall sub_416480(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi
  int v5; // edi
  _DWORD *v6; // ecx
  int v7; // edi
  int v8; // esi
  float v9[3]; // [esp+Ch] [ebp-Ch] BYREF

  result = this[8];
  switch ( result )
  {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
      result = sub_515C20(this, *(_DWORD *)(this[9] + 212), this[9] + 216);
      break;
    case 2:
      v4 = this[9];
      v5 = *(_DWORD *)(v4 + 212);
      v9[0] = *(double *)(v4 + 316);
      v9[1] = *(double *)(v4 + 324);
      v9[2] = *(double *)(v4 + 332);
      sub_5A12F0(1);
      sub_5155D0(v9);
      sub_5A0F50(v5, 1);
      result = sub_5A12F0(0);
      break;
    case 6:
      result = (int)off_5FD348 + 84;
      if ( (_UNKNOWN *)a2 != (_UNKNOWN *)((char *)off_5FD348 + 84) )
      {
        v6 = (_DWORD *)this[9];
        if ( v6 != (_DWORD *)result && (*(_BYTE *)(*v6 + 25296) & 1) != 0 )
        {
          if ( *(_DWORD *)(a2 + 16500) != 1
            || v6[4125] != 1
            || (result = dword_75AB98 / dword_62923C, !(dword_75AB98 % dword_62923C)) )
          {
            v7 = v6[453];
            sub_5A12F0(1);
            sub_5155D0(this[9] + 17544);
            sub_5A0F50(v7, 1);
            result = sub_5A12F0(0);
          }
        }
      }
      break;
    case 7:
      v8 = this[9];
      sub_5A12F0(1);
      sub_5155D0(0);
      sub_5A0F50(v8, 1);
      result = sub_5A12F0(0);
      break;
    default:
      return result;
  }
  return result;
}
