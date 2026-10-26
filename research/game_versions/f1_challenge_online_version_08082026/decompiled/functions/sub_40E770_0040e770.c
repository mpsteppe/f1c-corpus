char __thiscall sub_40E770(_DWORD *this, int a2, char a3)
{
  unsigned int v4; // edx
  int v5; // ecx
  void (**v6)(void); // eax
  int v7; // ecx
  _DWORD *v8; // eax
  char result; // al
  int v10; // [esp+8h] [ebp-18h] BYREF
  int v11; // [esp+Ch] [ebp-14h] BYREF
  int v12; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+14h] [ebp-Ch] BYREF
  int v14; // [esp+18h] [ebp-8h] BYREF
  int v15; // [esp+1Ch] [ebp-4h] BYREF

  sub_54FB40(0);
  v4 = this[7];
  if ( v4 <= 2 )
    sub_40E2B0(a2, v4);
  sub_54B530(&v10, &v11, &v12, &v13, &v14, &v15);
  switch ( this[7] )
  {
    case 0:
      v5 = this[8];
      v6 = *(void (***)(void))v5;
      *(_DWORD *)(v5 + 208) = a2;
      (*v6)();
      goto LABEL_6;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      v7 = this[8];
      *(_DWORD *)(v7 + 208) = a2;
      (**(void (__thiscall ***)(int))v7)(v7);
LABEL_6:
      v8 = (_DWORD *)this[8];
      v8[1] = v10;
      v8[2] = v11;
      v8[3] = v12;
      v8 += 4;
      *v8 = v13;
      v8[1] = v14;
      v8[2] = v15;
      break;
    default:
      break;
  }
  sub_40ED10(this);
  result = a3;
  if ( !a3 )
    return sub_4BE010(this);
  return result;
}
