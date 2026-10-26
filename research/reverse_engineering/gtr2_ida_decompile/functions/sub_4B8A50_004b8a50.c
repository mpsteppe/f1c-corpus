_DWORD *__thiscall sub_4B8A50(_DWORD *this, int a2)
{
  int v4; // [esp-8h] [ebp-5Ch]
  int v5; // [esp-4h] [ebp-58h]
  int v6; // [esp+50h] [ebp-4h]

  sub_4D8D20(1, -1);
  this[70] = 0;
  this[71] = -1;
  *this = &off_700C20;
  sub_409FB0(this + 13);
  this[72] = v6;
  switch ( v6 )
  {
    case 583:
    case 584:
      sub_4D3CF0(off_6F1D6C, -1);
      sub_4D3CF0("Normal", -1);
      sub_4D3CF0(&unk_6FE070, -1);
      sub_4D3CF0(&unk_6FE06C, -1);
      sub_4D3CF0(&unk_6FE068, -1);
      sub_4D3CF0(&unk_6FE064, -1);
      sub_4D3CF0(&unk_6FE060, -1);
      sub_4D3CF0(&unk_6FE05C, -1);
      return this;
    case 585:
      sub_4D3CF0("None", -1);
      sub_4D3CF0("Black Only", -1);
      goto LABEL_6;
    case 586:
      sub_4D3CF0(off_6F1D6C, -1);
      sub_4D3CF0("Normal", -1);
      sub_4D3CF0("Time Scaled", -1);
      goto LABEL_6;
    case 587:
    case 588:
    case 589:
    case 590:
    case 591:
    case 592:
    case 593:
    case 594:
    case 595:
      sub_4D3CF0("Allowed", -1);
LABEL_6:
      sub_4D3CF0(v4, v5);
      break;
    default:
      return this;
  }
  return this;
}
