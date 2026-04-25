// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   matrix.rs                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2026/04/25 15:50:04 by lumugot           #+#    #+#             //
//   Updated: 2026/04/25 15:58:18 by lumugot          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

use std::fmt;

pub struct Matrix<K> {
	pub data: Vec<Vec<K>>,
}

impl<K: Clone> Matrix<K> {
	pub fn from(data: &[Vec<K>]) -> Self
	{
		Matrix { data: data.to_vec() }
	}

	pub fn shape(&self) -> (usize, usize)
	{
		let rows = self.data.len();
		let cols = if rows > 0 { self.data[0].len() } else { 0 };

		(rows, cols)
	}

	pub fn is_square(&self) -> bool
	{
		let (rows, cols) = self.shape();

		rows == cols
	}
}

impl<K: fmt::Display>	fmt::Display for Matrix<K> {
	fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result
	{
		for row in &self.data
		{
			let row_str: Vec<String> = row.iter().map(|x| x.to_string()).collect();

			writeln!(f, "[{}]", row_str.join(", "))?;
		}
		Ok(())
	}
}
