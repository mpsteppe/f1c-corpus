int __thiscall UITextFieldInitialization(int this)
{
  int result; // eax

  switch ( *(_DWORD *)(this + 772) )
  {
    case 0x1AF:
      byte_7CD818 = 0;
      UtilityFunction_b7e0((int *)this, (int)&byte_7CD818, 26);
      *(_DWORD *)(this + 764) = aWwwwwwwwwwwwww;
      result = 0;
      break;
    case 0x1B0:
      byte_7CD834 = 0;
      *(_DWORD *)(this + 744) = 0;
      UtilityFunction_b7e0((int *)this, (int)&byte_7CD834, 26);
      *(_DWORD *)(this + 764) = aWwwwwwwwwwwwww_0;
      result = 0;
      break;
    case 0x1B1:
      byte_7CD850 = 0;
      *(_DWORD *)(this + 744) = 0;
      UtilityFunction_b7e0((int *)this, (int)&byte_7CD850, 15);
      result = 0;
      break;
    case 0x1B2:
      UtilityFunction_b7e0((int *)this, (int)&unk_7CD860, 32);
      *(_DWORD *)(this + 744) = 2;
      result = 0;
      break;
    case 0x1B3:
      *(_DWORD *)(this + 744) = 0;
      BoundedFieldSetter((_DWORD *)this, 0xA0u);
      *(_BYTE *)(this + 229) = 1;
      result = 0;
      break;
    case 0x1B5:
      byte_7CD880 = 0;
      UtilityFunction_b7e0((int *)this, (int)&byte_7CD880, 32);
      goto LABEL_8;
    default:
LABEL_8:
      result = 0;
      break;
  }
  return result;
}
