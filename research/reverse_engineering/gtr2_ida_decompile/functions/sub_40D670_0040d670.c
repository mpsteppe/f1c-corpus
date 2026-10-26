__int32 __usercall sub_40D670@<eax>(__int32 a1@<ecx>, __int32 a2@<ebp>, __int32 a3@<esi>)
{
  __int32 result; // eax
  __int32 v4; // [esp+0h] [ebp-4h] BYREF

  result = 0;
  switch ( *(_DWORD *)(a1 + 52) )
  {
    case 0:
      v4 = *(_DWORD *)(a1 + 52);
      _InterlockedExchange(&v4, dword_16C6F60 + 768409235);
      break;
    case 1:
      v4 = a1;
      _InterlockedExchange(&v4, dword_16C6F50 + 598566913);
      break;
    case 2:
      v4 = a2;
      _InterlockedExchange(&v4, __ROL4__(dword_16C6F58, 108));
      break;
    case 3:
      v4 = 0;
      result = _InterlockedExchange(&v4, (__int32)&dword_16CB6D4 + dword_16C6F48 + 1);
      break;
    case 4:
      v4 = 0;
      result = _InterlockedExchange(&v4, dword_16C6F5C - dword_16DE027);
      break;
    case 5:
      v4 = a3;
      _InterlockedExchange(&v4, __ROR4__(dword_16C6F4C, *(&sub_5D3270 + 1)));
      break;
    case 6:
      v4 = *(_DWORD *)(a1 + 52);
      _InterlockedExchange(&v4, __ROL4__(off_16C6F54, (char)&dword_16CB960));
      break;
    case 7:
      v4 = *(_DWORD *)(a1 + 52);
      _InterlockedExchange(&v4, __ROL4__(dword_16C6F44, 37));
      break;
    case 8:
      result = def_40D67A();
      break;
    default:
      JUMPOUT(0x40D6AF);
  }
  return result;
}
