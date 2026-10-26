double *__thiscall sub_55F290(int this, _DWORD *a2, const void *a3, int a4)
{
  void *v4; // edi
  void *v5; // edi
  double *result; // eax
  double *v7; // edx
  double v8[62]; // [esp+Ch] [ebp-1F0h] BYREF

  switch ( *a2 )
  {
    case 1:
      v4 = (void *)(this + 24);
      goto LABEL_12;
    case 2:
      goto LABEL_4;
    case 3:
      goto LABEL_6;
    case 4:
      goto LABEL_11;
    case 5:
      qmemcpy((void *)(this + 24), a3, 0x1F0u);
LABEL_4:
      v4 = (void *)(this + 520);
      goto LABEL_12;
    case 6:
      goto LABEL_9;
    case 7:
      qmemcpy((void *)(this + 24), a3, 0x1F0u);
LABEL_6:
      v4 = (void *)(this + 1016);
      goto LABEL_12;
    case 8:
      v5 = (void *)(this + 520);
      goto LABEL_10;
    case 9:
      qmemcpy((void *)(this + 24), a3, 0x1F0u);
      qmemcpy((void *)(this + 520), a3, 0x1F0u);
LABEL_9:
      v5 = (void *)(this + 1016);
LABEL_10:
      qmemcpy(v5, a3, 0x1F0u);
LABEL_11:
      v4 = (void *)(this + 1512);
LABEL_12:
      qmemcpy(v4, a3, 0x1F0u);
      break;
    default:
      break;
  }
  *a2 = a4;
  result = sub_55F020(v8);
  qmemcpy(v7, result, 0x1F0u);
  return result;
}
