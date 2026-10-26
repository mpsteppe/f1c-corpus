_DWORD *__thiscall sub_4B88B0(_DWORD *this, int a2)
{
  int v4; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+Ch] [ebp-28h]
  int v6; // [esp+30h] [ebp-4h]

  sub_4D8D20(1, -1);
  this[70] = 0;
  this[71] = -1;
  *this = &off_700B80;
  sub_409FB0(this + 13);
  this[72] = v6;
  switch ( v6 )
  {
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
    case 559:
    case 560:
    case 561:
    case 562:
    case 563:
      sub_4D3CF0("Allowed", -1);
      sub_4D3CF0("Disallowed", -1);
      return this;
    case 567:
      sub_4D3CF0("None", -1);
      sub_4D3CF0("Black Only", -1);
      goto LABEL_6;
    case 568:
    case 569:
      sub_4D3CF0(off_6F1D6C, -1);
      sub_4D3CF0("Normal", -1);
      sub_4D3CF0(&unk_6FE070, -1);
      sub_4D3CF0(&unk_6FE06C, -1);
      sub_4D3CF0(&unk_6FE068, -1);
      sub_4D3CF0(&unk_6FE064, -1);
      sub_4D3CF0(&unk_6FE060, -1);
      goto LABEL_6;
    case 570:
      sub_4D3CF0(off_6F1D6C, -1);
      sub_4D3CF0("Normal", -1);
      sub_4D3CF0("Time Scaled", -1);
LABEL_6:
      sub_4D3CF0(v4, v5);
      break;
    default:
      return this;
  }
  return this;
}
