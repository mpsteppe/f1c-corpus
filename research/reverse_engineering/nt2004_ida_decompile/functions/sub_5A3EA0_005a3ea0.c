int __thiscall sub_5A3EA0(int this, int a2)
{
  int *v3; // eax
  int v4; // ecx

  switch ( *(_DWORD *)(*(_DWORD *)(this + 180) + 48) )
  {
    case 5:
    case 6:
      sub_5A3A90(this);
      break;
    case 7:
    case 8:
      sub_5A3CC0(this);
      break;
    default:
      break;
  }
  v3 = *(int **)(this + 180);
  v4 = *(_DWORD *)(this + 108);
  *(float *)(this + 4) = 1.0 / (double)v3[7];
  *(float *)(this + 8) = 1.0 / (double)v3[8];
  v3[13] = v4;
  return 0;
}
