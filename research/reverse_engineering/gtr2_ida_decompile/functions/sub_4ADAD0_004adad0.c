int __usercall sub_4ADAD0@<eax>(_DWORD *a1@<ecx>, __int32 a2@<ebx>, __int32 a3@<ebp>)
{
  unsigned int v3; // kr00_4
  int *v5; // edi
  int result; // eax
  int v7; // esi
  __int32 v8[5]; // [esp+0h] [ebp-1Ch] BYREF

  v5 = a1 + 184;
  v8[3] = (__int32)(a1 + 184);
  sub_499D90();
  result = 28 * a1[181];
  *(int *)((char *)&dword_B74800 + result) = *v5;
  *(int *)((char *)&dword_B74804 + result) = v5[1];
  if ( *v5 == 1 )
  {
    v7 = a1[185];
    result = v7 - 1;
    switch ( v7 )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 40:
      case 41:
      case 42:
      case 43:
      case 44:
      case 45:
      case 46:
      case 47:
      case 48:
      case 49:
      case 50:
      case 51:
      case 132:
      case 133:
      case 134:
      case 135:
      case 136:
      case 137:
      case 138:
      case 139:
        v8[2] = a2;
        v8[1] = a3;
        v8[0] = (__int32)off_16C9A40;
        v3 = __readeflags();
        _InterlockedExchange(v8, __ROR4__(dword_16C6D5C, *(char *)sub_52B980));
        __writeeflags(v3);
        break;
      default:
        return result;
    }
  }
  return result;
}
