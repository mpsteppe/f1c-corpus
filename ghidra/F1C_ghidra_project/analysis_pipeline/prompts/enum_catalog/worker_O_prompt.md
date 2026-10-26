# WORKER O — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker O of 20, items 4635–4965.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_O.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

4635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403640__FUN_00403640.c
4636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404a50__FUN_00404a50.c
4637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405160__FUN_00405160.c
4638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405d70__sub_405D70.c
4639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406ab0__FUN_00406ab0.c
4640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407dd0__FUN_00407dd0.c
4641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408420__FUN_00408420.c
4642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a890__FUN_0040a890.c
4643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b6f0__FUN_0040b6f0.c
4644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c8d0__FUN_0040c8d0.c
4645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d490__FUN_0040d490.c
4646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e6d0__FUN_0040e6d0.c
4647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f380__FUN_0040f380.c
4648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411120__FUN_00411120.c
4649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00412490__FUN_00412490.c
4650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414490__FUN_00414490.c
4651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004156c0__FUN_004156c0.c
4652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418ac0__FUN_00418ac0.c
4653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a170__FUN_0041a170.c
4654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041c090__FUN_0041c090.c
4655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f180__FUN_0041f180.c
4656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004218d0__FUN_004218d0.c
4657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423060__FUN_00423060.c
4658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424b20__FUN_00424b20.c
4659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429fd0__FUN_00429fd0.c
4660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ae90__FUN_0042ae90.c
4661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ce10__FUN_0042ce10.c
4662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e470__FUN_0042e470.c
4663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431850__FUN_00431850.c
4664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004328c0__FUN_004328c0.c
4665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004339e0__FUN_004339e0.c
4666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434d60__FUN_00434d60.c
4667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004366e0__FUN_004366e0.c
4668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043bbd0__FUN_0043bbd0.c
4669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ff3d__FUN_0043ff3d.c
4670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00443f71__FUN_00443f71.c
4671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004482d0__FUN_004482d0.c
4672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448f00__FUN_00448f00.c
4673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a430__FUN_0044a430.c
4674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c470__FUN_0044c470.c
4675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c8f0__FUN_0044c8f0.c
4676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cbd4__sub_44CBD4.c
4677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce60__FUN_0044ce60.c
4678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d100__FUN_0044d100.c
4679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d490__FUN_0044d490.c
4680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d850__FUN_0044d850.c
4681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc10__FUN_0044dc10.c
4682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dfd0__FUN_0044dfd0.c
4683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e390__FUN_0044e390.c
4684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e750__FUN_0044e750.c
4685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb10__FUN_0044eb10.c
4686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f0e0__FUN_0044f0e0.c
4687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fee0__FUN_0044fee0.c
4688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004542d0__FUN_004542d0.c
4689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456130__FUN_00456130.c
4690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00458020__FUN_00458020.c
4691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045af50__sub_45AF50.c
4692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb60__FUN_0045bb60.c
4693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c0a0__FUN_0045c0a0.c
4694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cf30__FUN_0045cf30.c
4695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ebd0__FUN_0045ebd0.c
4696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461550__FUN_00461550.c
4697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462330__FUN_00462330.c
4698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462e00__FUN_00462e00.c
4699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463e00__FUN_00463e00.c
4700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464b10__FUN_00464b10.c
4701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465c70__FUN_00465c70.c
4702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466910__FUN_00466910.c
4703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004685f0__FUN_004685f0.c
4704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a970__FUN_0046a970.c
4705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cb00__FUN_0046cb00.c
4706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e1b0__sub_46E1B0.c
4707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fdf0__FUN_0046fdf0.c
4708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470f20__sub_470F20.c
4709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472510__FUN_00472510.c
4710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473cc0__FUN_00473cc0.c
4711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004750f0__FUN_004750f0.c
4712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476240__sub_476240.c
4713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477680__FUN_00477680.c
4714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478220__FUN_00478220.c
4715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479760__FUN_00479760.c
4716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479ca0__FUN_00479ca0.c
4717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a5e0__FUN_0047a5e0.c
4718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bc90__FUN_0047bc90.c
4719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047d060__FUN_0047d060.c
4720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f370__FUN_0047f370.c
4721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004858e0__FUN_004858e0.c
4722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486300__FUN_00486300.c
4723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004868c0__FUN_004868c0.c
4724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487330__FUN_00487330.c
4725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487e10__FUN_00487e10.c
4726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488bd0__FUN_00488bd0.c
4727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489a10__FUN_00489a10.c
4728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048aed0__FUN_0048aed0.c
4729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c170__FUN_0048c170.c
4730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3a0__FUN_0048d3a0.c
4731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e300__FUN_0048e300.c
4732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f1a0__FUN_0048f1a0.c
4733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe60__FUN_0048fe60.c
4734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490850__sub_490850.c
4735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491710__FUN_00491710.c
4736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e80__FUN_00491e80.c
4737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494f00__FUN_00494f00.c
4738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495580__FUN_00495580.c
4739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004963c0__FUN_004963c0.c
4740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004975d0__FUN_004975d0.c
4741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004980c0__FUN_004980c0.c
4742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d00__FUN_00498d00.c
4743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499260__FUN_00499260.c
4744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499910__FUN_00499910.c
4745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499df0__FUN_00499df0.c
4746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a1c0__FUN_0049a1c0.c
4747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a9e0__FUN_0049a9e0.c
4748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b020__FUN_0049b020.c
4749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049bad0__FUN_0049bad0.c
4750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049de40__FUN_0049de40.c
4751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ec60__FUN_0049ec60.c
4752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0000__FUN_004a0000.c
4753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0db0__FUN_004a0db0.c
4754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b20__FUN_004a1b20.c
4755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2840__FUN_004a2840.c
4756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40e0__FUN_004a40e0.c
4757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5bd0__FUN_004a5bd0.c
4758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a7010__FUN_004a7010.c
4759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0390__FUN_004b0390.c
4760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1990__FUN_004b1990.c
4761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1fc0__sub_4B1FC0.c
4762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2930__FUN_004b2930.c
4763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c80__FUN_004b2c80.c
4764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3dc0__FUN_004b3dc0.c
4765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b48e0__FUN_004b48e0.c
4766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5be0__FUN_004b5be0.c
4767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b71e0__FUN_004b71e0.c
4768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8940__FUN_004b8940.c
4769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9b80__FUN_004b9b80.c
4770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba1e0__FUN_004ba1e0.c
4771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bad70__FUN_004bad70.c
4772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb8e0__FUN_004bb8e0.c
4773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7b0__FUN_004bd7b0.c
4774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be4e0__FUN_004be4e0.c
4775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c01a0__FUN_004c01a0.c
4776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c15a0__FUN_004c15a0.c
4777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c29f0__FUN_004c29f0.c
4778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3130__FUN_004c3130.c
4779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c50e0__FUN_004c50e0.c
4780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c69b0__FUN_004c69b0.c
4781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c40__FUN_004c7c40.c
4782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c85a0__FUN_004c85a0.c
4783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9000__FUN_004c9000.c
4784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9b90__sub_4C9B90.c
4785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb620__FUN_004cb620.c
4786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cdbf0__FUN_004cdbf0.c
4787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0b20__FUN_004d0b20.c
4788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1cd0__FUN_004d1cd0.c
4789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47a0__FUN_004d47a0.c
4790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c40__FUN_004d5c40.c
4791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7c00__FUN_004d7c00.c
4792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d82d0__FUN_004d82d0.c
4793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d98a0__FUN_004d98a0.c
4794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db0e0__FUN_004db0e0.c
4795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbf90__FUN_004dbf90.c
4796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd06__sub_4DCD06.c
4797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4c0__FUN_004dd4c0.c
4798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfb00__FUN_004dfb00.c
4799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e19a0__FUN_004e19a0.c
4800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3050__FUN_004e3050.c
4801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4f40__FUN_004e4f40.c
4802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9537__FUN_004e9537.c
4803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed1c0__FUN_004ed1c0.c
4804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef6c0__FUN_004ef6c0.c
4805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1510__FUN_004f1510.c
4806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f23b0__FUN_004f23b0.c
4807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6b40__FUN_004f6b40.c
4808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8850__FUN_004f8850.c
4809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9150__FUN_004f9150.c
4810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004faec0__FUN_004faec0.c
4811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd6f0__FUN_004fd6f0.c
4812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fffa0__thunk_FUN_00500170.c
4813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050099c__FUN_0050099c.c
4814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502c12__sub_502C12.c
4815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050415c__FUN_0050415c.c
4816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050696c__thunk_FUN_0050653e.c
4817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508105__FUN_00508105.c
4818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005093f9__FUN_005093f9.c
4819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a0f0__FUN_0050a0f0.c
4820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae22__FUN_0050ae22.c
4821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b3d1__FUN_0050b3d1.c
4822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b879__FUN_0050b879.c
4823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c4bb__FUN_0050c4bb.c
4824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cdf9__thunk_FUN_0050cdec.c
4825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d85d__FUN_0050d85d.c
4826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e055__FUN_0050e055.c
4827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e7cb__FUN_0050e7cb.c
4828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fb3b__FUN_0050fb3b.c
4829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005114d5__sub_5114D5.c
4830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512144__FUN_00512144.c
4831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512e1a__FUN_00512e1a.c
4832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513e2d__FUN_00513e2d.c
4833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005159c3__FUN_005159c3.c
4834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051664f__FUN_0051664f.c
4835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005176ec__FUN_005176ec.c
4836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519346__FUN_00519346.c
4837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a4b7__FUN_0051a4b7.c
4838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bdf1__FUN_0051bdf1.c
4839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cc8e__FUN_0051cc8e.c
4840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e0cd__sub_51E0CD.c
4841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ee7e__sub_51EE7E.c
4842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051fd2e__sub_51FD2E.c
4843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521295__sub_521295.c
4844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522b22__FUN_00522b22.c
4845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00526b55__FUN_00526b55.c
4846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
4847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d9b0__FUN_0052d9b0.c
4848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e4e0__FUN_0052e4e0.c
4849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ac0__FUN_00534ac0.c
4850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535660__FUN_00535660.c
4851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537e40__FUN_00537e40.c
4852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539830__FUN_00539830.c
4853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b170__FUN_0053b170.c
4854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c1b0__FUN_0053c1b0.c
4855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053caf0__FUN_0053caf0.c
4856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d470__FUN_0053d470.c
4857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540250__FUN_00540250.c
4858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005414e0__FUN_005414e0.c
4859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542400__FUN_00542400.c
4860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543540__FUN_00543540.c
4861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544ef0__FUN_00544ef0.c
4862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545850__FUN_00545850.c
4863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546f70__FUN_00546f70.c
4864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005477f0__FUN_005477f0.c
4865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548e20__FUN_00548e20.c
4866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a1c0__FUN_0054a1c0.c
4867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b450__FUN_0054b450.c
4868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c0e0__FUN_0054c0e0.c
4869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d520__FUN_0054d520.c
4870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eec1__sub_54EEC1.c
4871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fcb0__FUN_0054fcb0.c
4872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005507a0__FUN_005507a0.c
4873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551790__FUN_00551790.c
4874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552ba0__FUN_00552ba0.c
4875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553d00__FUN_00553d00.c
4876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554c30__FUN_00554c30.c
4877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005566d0__FUN_005566d0.c
4878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556d60__FUN_00556d60.c
4879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558c60__FUN_00558c60.c
4880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559a30__FUN_00559a30.c
4881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055be20__FUN_0055be20.c
4882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c9a0__FUN_0055c9a0.c
4883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d4f0__FUN_0055d4f0.c
4884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560230__FUN_00560230.c
4885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560fc0__FUN_00560fc0.c
4886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561ed0__FUN_00561ed0.c
4887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562d20__FUN_00562d20.c
4888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563eb0__FUN_00563eb0.c
4889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564650__FUN_00564650.c
4890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564ab0__FUN_00564ab0.c
4891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565ed0__FUN_00565ed0.c
4892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566bd0__FUN_00566bd0.c
4893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567580__FUN_00567580.c
4894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567ba2__sub_567BA2.c
4895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568b00__FUN_00568b00.c
4896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005697f0__FUN_005697f0.c
4897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c2c4__sub_56C2C4.c
4898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056eb30__FUN_0056eb30.c
4899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579fc0__FUN_00579fc0.c
4900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a4c0__FUN_0057a4c0.c
4901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a880__FUN_0057a880.c
4902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057acb0__FUN_0057acb0.c
4903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b550__FUN_0057b550.c
4904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bc70__FUN_0057bc70.c
4905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057dff0__FUN_0057dff0.c
4906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057f2b0__FUN_0057f2b0.c
4907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005818e0__FUN_005818e0.c
4908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005824f0__FUN_005824f0.c
4909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583360__FUN_00583360.c
4910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583d90__FUN_00583d90.c
4911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585380__FUN_00585380.c
4912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e20__FUN_00585e20.c
4913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586560__FUN_00586560.c
4914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f10__FUN_00586f10.c
4915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587310__FUN_00587310.c
4916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587720__FUN_00587720.c
4917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587ca0__FUN_00587ca0.c
4918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884e0__FUN_005884e0.c
4919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588e4e__FUN_00588e4e.c
4920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589901__FUN_00589901.c
4921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589ffd__FUN_00589ffd.c
4922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a5f7__FUN_0058a5f7.c
4923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058abf1__FUN_0058abf1.c
4924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b92a__FUN_0058b92a.c
4925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c1e0__FUN_0058c1e0.c
4926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d7c3__FUN_0058d7c3.c
4927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd75__FUN_0058dd75.c
4928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ef5f__FUN_0058ef5f.c
4929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005901f0__FUN_005901f0.c
4930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005910b6__FUN_005910b6.c
4931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591edf__FUN_00591edf.c
4932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593446__FUN_00593446.c
4933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059416f__FUN_0059416f.c
4934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005952e9__FUN_005952e9.c
4935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595ae2__FUN_00595ae2.c
4936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596c80__FUN_00596c80.c
4937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005975f4__FUN_005975f4.c
4938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598642__htonl.c
4939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986df__FUN_005986df.c
4940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598815__FUN_00598815.c
4941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e39__FUN_00598e39.c
4942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599495__FUN_00599495.c
4943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599802__FUN_00599802.c
4944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599942__FUN_00599942.c
4945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a221__FUN_0059a221.c
4946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a5e9__FUN_0059a5e9.c
4947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aaaf__sub_59AAAF.c
4948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b038__FUN_0059b038.c
4949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bacc__FUN_0059bacc.c
4950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c400__Unwind_0059c400.c
4951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c518__Unwind_0059c518.c
4952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c620__Unwind_0059c620.c
4953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6e8__Unwind_0059c6e8.c
4954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c83e__Unwind_0059c83e.c
4955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c948__Unwind_0059c948.c
4956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cac0__Unwind_0059cac0.c
4957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc1e__Unwind_0059cc1e.c
4958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd80__Unwind_0059cd80.c
4959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cef5__Unwind_0059cef5.c
4960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d012__Unwind_0059d012.c
4961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d118__Unwind_0059d118.c
4962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2c7__Unwind_0059d2c7.c
4963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d470__Unwind_0059d470.c
4964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d6ff__FUN_0059d6ff.c
4965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059db88__FUN_0059db88.c

## TASK
For each .c file:
1. Find switch statements — extract case values and purposes
2. Find comparisons against literal integers (if x == 3, if x < 7, etc.)
3. Find assignments of literal values to globals/struct fields
4. Group related values into enum candidates

## OUTPUT FORMAT

```
=== ENUM DISCOVERIES ===

### EnumName (new or extension of existing)
Source evidence: FUN_XXXXXXXX, FUN_YYYYYYYY
Variable: DAT_XXXXXXXX or param_1+0xNNN

| Value | Meaning | Evidence | Confidence |
|-------|---------|----------|------------|

=== MAGIC NUMBERS ===
| Value | Hex | Type | Used In | Likely Meaning |
|-------|-----|------|---------|---------------|
| 0.017453 | — | float | FUN_X | DEG_TO_RAD |
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_O.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
