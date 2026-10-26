# WORKER R — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker R of 20, items 5627–5956.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_R.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (330)

5627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403aa0__FUN_00403aa0.c
5628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d00__FUN_00404d00.c
5629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405440__FUN_00405440.c
5630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406020__FUN_00406020.c
5631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406b80__FUN_00406b80.c
5632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407ef0__FUN_00407ef0.c
5633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004084a0__FUN_004084a0.c
5634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ac00__FUN_0040ac00.c
5635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040bd10__FUN_0040bd10.c
5636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040cd60__FUN_0040cd60.c
5637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040da00__FUN_0040da00.c
5638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e860__FUN_0040e860.c
5639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f600__FUN_0040f600.c
5640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411570__FUN_00411570.c
5641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004133b0__FUN_004133b0.c
5642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144d0__FUN_004144d0.c
5643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415780__FUN_00415780.c
5644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418c10__FUN_00418c10.c
5645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a3a0__FUN_0041a3a0.c
5646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041c440__FUN_0041c440.c
5647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f220__FUN_0041f220.c
5648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421930__FUN_00421930.c
5649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423490__FUN_00423490.c
5650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424e30__FUN_00424e30.c
5651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a3d0__FUN_0042a3d0.c
5652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042af40__FUN_0042af40.c
5653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042d350__FUN_0042d350.c
5654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042eb60__FUN_0042eb60.c
5655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004319da__sub_4319DA.c
5656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432920__FUN_00432920.c
5657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433e60__FUN_00433e60.c
5658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435270__FUN_00435270.c
5659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438100__FUN_00438100.c
5660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e050__FUN_0043e050.c
5661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441360__FUN_00441360.c
5662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00446fd0__FUN_00446fd0.c
5663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448480__FUN_00448480.c
5664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004491c0__FUN_004491c0.c
5665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a700__FUN_0044a700.c
5666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c5e0__FUN_0044c5e0.c
5667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c980__FUN_0044c980.c
5668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc34__sub_44CC34.c
5669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cec0__FUN_0044cec0.c
5670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d190__FUN_0044d190.c
5671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d520__FUN_0044d520.c
5672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d8e0__FUN_0044d8e0.c
5673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dca0__FUN_0044dca0.c
5674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e060__FUN_0044e060.c
5675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e420__FUN_0044e420.c
5676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e7e0__FUN_0044e7e0.c
5677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eba0__FUN_0044eba0.c
5678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f4a0__FUN_0044f4a0.c
5679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004526c0__FUN_004526c0.c
5680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c
5681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456280__FUN_00456280.c
5682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582e0__FUN_004582e0.c
5683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b310__FUN_0045b310.c
5684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bc00__FUN_0045bc00.c
5685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c3c0__FUN_0045c3c0.c
5686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d130__sub_45D130.c
5687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045f2b0__FUN_0045f2b0.c
5688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004615f0__FUN_004615f0.c
5689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004623b0__FUN_004623b0.c
5690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004630d0__FUN_004630d0.c
5691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004643c0__FUN_004643c0.c
5692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464bd0__FUN_00464bd0.c
5693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465ff0__FUN_00465ff0.c
5694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466a30__FUN_00466a30.c
5695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004692a0__FUN_004692a0.c
5696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ad50__FUN_0046ad50.c
5697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d060__FUN_0046d060.c
5698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e600__FUN_0046e600.c
5699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fe80__FUN_0046fe80.c
5700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004713e0__sub_4713E0.c
5701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472720__FUN_00472720.c
5702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473ed0__FUN_00473ed0.c
5703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475530__FUN_00475530.c
5704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476600__FUN_00476600.c
5705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477830__FUN_00477830.c
5706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004782c0__FUN_004782c0.c
5707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004797f0__FUN_004797f0.c
5708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479db0__FUN_00479db0.c
5709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a800__FUN_0047a800.c
5710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be00__FUN_0047be00.c
5711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047e384__sub_47E384.c
5712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047fb10__FUN_0047fb10.c
5713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004859d0__sub_4859D0.c
5714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486340__FUN_00486340.c
5715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486ac0__FUN_00486ac0.c
5716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487460__FUN_00487460.c
5717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f10__FUN_00487f10.c
5718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488f90__FUN_00488f90.c
5719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489ba0__FUN_00489ba0.c
5720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b420__FUN_0048b420.c
5721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c9b0__FUN_0048c9b0.c
5722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d4b0__FUN_0048d4b0.c
5723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e4b0__FUN_0048e4b0.c
5724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f590__FUN_0048f590.c
5725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fec0__FUN_0048fec0.c
5726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490940__FUN_00490940.c
5727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491770__FUN_00491770.c
5728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491fb0__FUN_00491fb0.c
5729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494fb0__FUN_00494fb0.c
5730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495810__FUN_00495810.c
5731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496750__FUN_00496750.c
5732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497750__FUN_00497750.c
5733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004982c0__FUN_004982c0.c
5734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d90__FUN_00498d90.c
5735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499360__FUN_00499360.c
5736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a20__FUN_00499a20.c
5737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e20__FUN_00499e20.c
5738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a270__FUN_0049a270.c
5739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aa70__FUN_0049aa70.c
5740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b060__FUN_0049b060.c
5741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049c600__FUN_0049c600.c
5742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e410__FUN_0049e410.c
5743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ed00__FUN_0049ed00.c
5744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a03f0__FUN_004a03f0.c
5745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0de8__sub_4A0DE8.c
5746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1d10__FUN_004a1d10.c
5747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2a40__FUN_004a2a40.c
5748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4110__FUN_004a4110.c
5749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5c80__FUN_004a5c80.c
5750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8af0__FUN_004a8af0.c
5751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0720__FUN_004b0720.c
5752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b19f0__FUN_004b19f0.c
5753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2180__FUN_004b2180.c
5754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b29f0__FUN_004b29f0.c
5755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b32a0__FUN_004b32a0.c
5756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b41e0__FUN_004b41e0.c
5757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4e10__FUN_004b4e10.c
5758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5e30__FUN_004b5e30.c
5759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7860__FUN_004b7860.c
5760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8c40__FUN_004b8c40.c
5761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cc0__FUN_004b9cc0.c
5762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba770__FUN_004ba770.c
5763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004baf10__FUN_004baf10.c
5764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbed0__FUN_004bbed0.c
5765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd800__FUN_004bd800.c
5766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be9e0__FUN_004be9e0.c
5767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c03c0__FUN_004c03c0.c
5768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c16b0__FUN_004c16b0.c
5769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c00__FUN_004c2c00.c
5770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3f80__FUN_004c3f80.c
5771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c55b0__FUN_004c55b0.c
5772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6d90__FUN_004c6d90.c
5773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c80__FUN_004c7c80.c
5774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8630__FUN_004c8630.c
5775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9260__FUN_004c9260.c
5776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9c70__FUN_004c9c70.c
5777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cbdd0__FUN_004cbdd0.c
5778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce3e0__FUN_004ce3e0.c
5779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0ec0__FUN_004d0ec0.c
5780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1d80__FUN_004d1d80.c
5781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4800__FUN_004d4800.c
5782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c70__FUN_004d5c70.c
5783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7cf0__FUN_004d7cf0.c
5784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8840__FUN_004d8840.c
5785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9f80__FUN_004d9f80.c
5786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db120__sub_4DB120.c
5787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc220__FUN_004dc220.c
5788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd80__FUN_004dcd80.c
5789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd550__FUN_004dd550.c
5790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfbb0__FUN_004dfbb0.c
5791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2070__FUN_004e2070.c
5792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e38d0__FUN_004e38d0.c
5793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e513e__FUN_004e513e.c
5794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e96c0__FUN_004e96c0.c
5795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed250__FUN_004ed250.c
5796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efa40__FUN_004efa40.c
5797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1650__FUN_004f1650.c
5798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f2b50__FUN_004f2b50.c
5799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6bc0__FUN_004f6bc0.c
5800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8a70__FUN_004f8a70.c
5801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f91b0__FUN_004f91b0.c
5802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb2e0__FUN_004fb2e0.c
5803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd8b0__FUN_004fd8b0.c
5804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005000c0__FUN_005000c0.c
5805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500f3c__FUN_00500f3c.c
5806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502ee5__FUN_00502ee5.c
5807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504508__FUN_00504508.c
5808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506ce2__FUN_00506ce2.c
5809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005083d2__FUN_005083d2.c
5810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005096d0__FUN_005096d0.c
5811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a2b4__FUN_0050a2b4.c
5812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae76__FUN_0050ae76.c
5813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b425__thunk_FUN_00506ccc.c
5814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c021__thunk_FUN_0050b830.c
5815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c5bd__thunk_FUN_0050c5b0.c
5816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0af__FUN_0050d0af.c
5817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d97e__FUN_0050d97e.c
5818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e174__FUN_0050e174.c
5819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e927__FUN_0050e927.c
5820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fd88__Catch_0050fd88.c
5821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051166b__FUN_0051166b.c
5822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051227f__FUN_0051227f.c
5823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513482__FUN_00513482.c
5824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513f7a__FUN_00513f7a.c
5825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515d26__FUN_00515d26.c
5826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516883__FUN_00516883.c
5827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517927__FUN_00517927.c
5828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519361__FUN_00519361.c
5829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a794__FUN_0051a794.c
5830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bfa6__sub_51BFA6.c
5831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cdf9__FUN_0051cdf9.c
5832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e2ba__FUN_0051e2ba.c
5833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f160__sub_51F160.c
5834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ff8e__sub_51FF8E.c
5835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005215db__FUN_005215db.c
5836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522ce2__FUN_00522ce2.c
5837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005271ed__sub_5271ED.c
5838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529200__sub_529200.c
5839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052da10__FUN_0052da10.c
5840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e550__FUN_0052e550.c
5841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534aec__AVIStreamRelease.c
5842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536130__FUN_00536130.c
5843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537f30__FUN_00537f30.c
5844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053a630__FUN_0053a630.c
5845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b240__FUN_0053b240.c
5846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c2a0__FUN_0053c2a0.c
5847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ce10__FUN_0053ce10.c
5848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d850__FUN_0053d850.c
5849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005408f0__FUN_005408f0.c
5850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541670__FUN_00541670.c
5851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542490__FUN_00542490.c
5852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005437e0__FUN_005437e0.c
5853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545030__FUN_00545030.c
5854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005459d0__FUN_005459d0.c
5855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005470a0__FUN_005470a0.c
5856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547920__FUN_00547920.c
5857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549020__FUN_00549020.c
5858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a270__FUN_0054a270.c
5859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b530__FUN_0054b530.c
5860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c190__FUN_0054c190.c
5861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d9f0__FUN_0054d9f0.c
5862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f5c0__FUN_0054f5c0.c
5863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fd46__sub_54FD46.c
5864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550800__FUN_00550800.c
5865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551830__FUN_00551830.c
5866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552fc0__FUN_00552fc0.c
5867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553de0__FUN_00553de0.c
5868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554e04__sub_554E04.c
5869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556760__FUN_00556760.c
5870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557120__FUN_00557120.c
5871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558d10__FUN_00558d10.c
5872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559ad0__FUN_00559ad0.c
5873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bf70__FUN_0055bf70.c
5874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ca40__FUN_0055ca40.c
5875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d590__FUN_0055d590.c
5876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005604c0__FUN_005604c0.c
5877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005613e0__FUN_005613e0.c
5878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561f80__FUN_00561f80.c
5879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563020__FUN_00563020.c
5880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564000__sub_564000.c
5881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564690__FUN_00564690.c
5882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564c40__FUN_00564c40.c
5883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565f50__FUN_00565f50.c
5884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566cc0__FUN_00566cc0.c
5885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567740__FUN_00567740.c
5886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567d00__FUN_00567d00.c
5887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568c60__FUN_00568c60.c
5888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569990__FUN_00569990.c
5889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c540__FUN_0056c540.c
5890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056ec70__FUN_0056ec70.c
5891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a020__FUN_0057a020.c
5892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a570__FUN_0057a570.c
5893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a8e0__FUN_0057a8e0.c
5894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057adf0__FUN_0057adf0.c
5895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b680__FUN_0057b680.c
5896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bcb0__sub_57BCB0.c
5897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e410__FUN_0057e410.c
5898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057fc80__sub_57FC80.c
5899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581a20__FUN_00581a20.c
5900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582780__FUN_00582780.c
5901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005834c0__FUN_005834c0.c
5902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005840d0__FUN_005840d0.c
5903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585440__FUN_00585440.c
5904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e80__FUN_00585e80.c
5905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586670__FUN_00586670.c
5906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f70__FUN_00586f70.c
5907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587400__FUN_00587400.c
5908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587890__FUN_00587890.c
5909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587d7f__FUN_00587d7f.c
5910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588570__FUN_00588570.c
5911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589057__FUN_00589057.c
5912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589b70__FUN_00589b70.c
5913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a0b6__sub_58A0B6.c
5914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a6d5__sub_58A6D5.c
5915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ace6__FUN_0058ace6.c
5916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ba75__FUN_0058ba75.c
5917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c255__FUN_0058c255.c
5918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d839__FUN_0058d839.c
5919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058df5c__FUN_0058df5c.c
5920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f362__FUN_0058f362.c
5921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059033a__FUN_0059033a.c
5922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591574__sub_591574.c
5923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005921f3__FUN_005921f3.c
5924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059373e__FUN_0059373e.c
5925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594624__FUN_00594624.c
5926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059532b__FUN_0059532b.c
5927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595f11__FUN_00595f11.c
5928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596e0f__FUN_00596e0f.c
5929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597aa0__FUN_00597aa0.c
5930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598654__select.c
5931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059870c__FUN_0059870c.c
5932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598a41__FUN_00598a41.c
5933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599081__FUN_00599081.c
5934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599560__FUN_00599560.c
5935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059982f__FUN_0059982f.c
5936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599ad9__FUN_00599ad9.c
5937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a317__sub_59A317.c
5938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a70b__FUN_0059a70b.c
5939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059abcd__FUN_0059abcd.c
5940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b092__FUN_0059b092.c
5941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bbaf__FUN_0059bbaf.c
5942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c428__Unwind_0059c428.c
5943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c552__Unwind_0059c552.c
5944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c63e__Unwind_0059c63e.c
5945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c706__Unwind_0059c706.c
5946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c85c__Unwind_0059c85c.c
5947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c972__Unwind_0059c972.c
5948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb20__Unwind_0059cb20.c
5949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc6b__Unwind_0059cc6b.c
5950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cdc0__Unwind_0059cdc0.c
5951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf19__Unwind_0059cf19.c
5952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d036__Unwind_0059d036.c
5953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d15b__Unwind_0059d15b.c
5954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d308__Unwind_0059d308.c
5955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4ac__Unwind_0059d4ac.c
5956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d7d1__FUN_0059d7d1.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_R.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
