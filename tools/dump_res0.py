import pprint
import h3


def main():
    pprint.pprint(
        [
            list(map(list, h3.cell_to_boundary(c)))
            for c in h3.get_res0_cells()
        ]
    )


if __name__ == '__main__':
    main()
