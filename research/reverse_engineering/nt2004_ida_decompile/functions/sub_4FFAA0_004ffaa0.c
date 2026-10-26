_DWORD *__thiscall sub_4FFAA0(int this, _DWORD *a2, void *a3, int a4)
{
  char *v4; // eax
  int v5; // edx
  void *v6; // edi
  _DWORD *result; // eax
  int v8[128]; // [esp+10h] [ebp-200h] BYREF

  switch ( *a2 )
  {
    case 1:
      qmemcpy((void *)(this + 24), a3, 0x200u);
      break;
    case 2:
      goto LABEL_4;
    case 3:
      goto LABEL_8;
    case 4:
      goto LABEL_6;
    case 5:
      qmemcpy((void *)(this + 24), a3, 0x200u);
LABEL_4:
      qmemcpy((void *)(this + 536), a3, 0x200u);
      break;
    case 6:
      qmemcpy((void *)(this + 1048), a3, 0x200u);
LABEL_6:
      qmemcpy((void *)(this + 1560), a3, 0x200u);
      break;
    case 7:
      qmemcpy((void *)(this + 24), a3, 0x200u);
LABEL_8:
      qmemcpy((void *)(this + 1048), a3, 0x200u);
      break;
    case 8:
      qmemcpy((void *)(this + 536), a3, 0x200u);
      qmemcpy((void *)(this + 1560), a3, 0x200u);
      break;
    case 9:
      v4 = (char *)(this + 24);
      v5 = 4;
      do
      {
        v6 = v4;
        v4 += 512;
        --v5;
        qmemcpy(v6, a3, 0x200u);
      }
      while ( v5 );
      break;
    default:
      break;
  }
  *a2 = a4;
  result = sub_4FF780(v8);
  qmemcpy(a3, result, 0x200u);
  return result;
}
